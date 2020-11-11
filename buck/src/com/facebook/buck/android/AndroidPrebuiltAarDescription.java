/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.facebook.buck.android;

import com.facebook.buck.android.toolchain.AndroidPlatformTarget;
import com.facebook.buck.android.toolchain.AndroidTools;
import com.facebook.buck.core.cell.nameresolver.CellNameResolver;
import com.facebook.buck.core.description.arg.BuildRuleArg;
import com.facebook.buck.core.description.arg.HasDeclaredDeps;
import com.facebook.buck.core.description.attr.ImplicitDepsInferringDescription;
import com.facebook.buck.core.model.BuildTarget;
import com.facebook.buck.core.model.Flavor;
import com.facebook.buck.core.model.FlavorSet;
import com.facebook.buck.core.model.Flavored;
import com.facebook.buck.core.model.InternalFlavor;
import com.facebook.buck.core.model.TargetConfiguration;
import com.facebook.buck.core.rules.ActionGraphBuilder;
import com.facebook.buck.core.rules.BuildRule;
import com.facebook.buck.core.rules.BuildRuleCreationContextWithTargetGraph;
import com.facebook.buck.core.rules.BuildRuleParams;
import com.facebook.buck.core.rules.DescriptionWithTargetGraph;
import com.facebook.buck.core.sourcepath.ExplicitBuildTargetSourcePath;
import com.facebook.buck.core.sourcepath.SourcePath;
import com.facebook.buck.core.toolchain.ToolchainProvider;
import com.facebook.buck.core.toolchain.toolprovider.ToolProvider;
import com.facebook.buck.core.util.immutables.RuleArg;
import com.facebook.buck.io.filesystem.ProjectFilesystem;
import com.facebook.buck.jvm.core.JavaAbis;
import com.facebook.buck.jvm.java.CalculateClassAbi;
import com.facebook.buck.jvm.java.ExtraClasspathProvider;
import com.facebook.buck.jvm.java.JavacFactory;
import com.facebook.buck.jvm.java.JavacToJarStepFactory;
import com.facebook.buck.jvm.java.MaybeRequiredForSourceOnlyAbiArg;
import com.facebook.buck.jvm.java.PrebuiltJar;
import com.facebook.buck.jvm.java.toolchain.JavacOptionsProvider;
import com.google.common.base.Preconditions;
import com.google.common.collect.ImmutableCollection.Builder;
import com.google.common.collect.ImmutableSet;
import com.google.common.collect.ImmutableSortedSet;
import com.google.common.collect.Iterables;
import com.google.common.collect.Sets;
import java.util.Collections;
import java.util.Optional;
import org.immutables.value.Value;

/**
 * Description for a {@link BuildRule} that wraps an {@code .aar} file as an Android dependency.
 *
 * <p>This represents an Android Library Project packaged as an {@code .aar} bundle as specified by:
 * https://developer.android.com/studio/projects/android-library#aar-contents. When it is in the
 * packageable deps of an {@link AndroidBinary}, its contents will be included in the generated APK.
 *
 * <p>Note that the {@code aar} may be specified as a {@link SourcePath}, so it could be either a
 * binary {@code .aar} file checked into version control, or a zip file that conforms to the {@code
 * .aar} specification that is generated by another build rule.
 */
public class AndroidPrebuiltAarDescription
    implements DescriptionWithTargetGraph<AndroidPrebuiltAarDescriptionArg>,
        Flavored,
        ImplicitDepsInferringDescription<AndroidPrebuiltAarDescriptionArg> {

  private static final Flavor AAR_PREBUILT_JAR_FLAVOR = InternalFlavor.of("aar_prebuilt_jar");
  public static final Flavor AAR_UNZIP_FLAVOR = InternalFlavor.of("aar_unzip");

  private static final ImmutableSet<Flavor> KNOWN_FLAVORS =
      ImmutableSet.of(AAR_PREBUILT_JAR_FLAVOR, AAR_UNZIP_FLAVOR);

  @Override
  public boolean hasFlavors(
      ImmutableSet<Flavor> flavors, TargetConfiguration toolchainTargetConfiguration) {
    return Sets.difference(flavors, KNOWN_FLAVORS).isEmpty();
  }

  private final ToolchainProvider toolchainProvider;
  private final JavacFactory javacFactory;
  private final AndroidBuckConfig androidBuckConfig;

  public AndroidPrebuiltAarDescription(
      ToolchainProvider toolchainProvider, AndroidBuckConfig androidBuckConfig) {
    this.toolchainProvider = toolchainProvider;
    this.androidBuckConfig = androidBuckConfig;
    this.javacFactory = JavacFactory.getDefault(toolchainProvider);
  }

  @Override
  public Class<AndroidPrebuiltAarDescriptionArg> getConstructorArgType() {
    return AndroidPrebuiltAarDescriptionArg.class;
  }

  @Override
  public BuildRule createBuildRule(
      BuildRuleCreationContextWithTargetGraph context,
      BuildTarget buildTarget,
      BuildRuleParams params,
      AndroidPrebuiltAarDescriptionArg args) {
    ActionGraphBuilder graphBuilder = context.getActionGraphBuilder();
    ProjectFilesystem projectFilesystem = context.getProjectFilesystem();

    FlavorSet flavors = buildTarget.getFlavors();
    if (flavors.contains(AAR_UNZIP_FLAVOR)) {
      Preconditions.checkState(flavors.getSet().size() == 1);
      BuildRuleParams unzipAarParams =
          params
              .withoutDeclaredDeps()
              .withExtraDeps(
                  ImmutableSortedSet.copyOf(graphBuilder.filterBuildRuleInputs(args.getAar())));
      return new UnzipAar(buildTarget, projectFilesystem, unzipAarParams, args.getAar());
    }

    BuildRule unzipAarRule = graphBuilder.requireRule(buildTarget.withFlavors(AAR_UNZIP_FLAVOR));
    Preconditions.checkState(
        unzipAarRule instanceof UnzipAar,
        "aar_unzip flavor created rule of unexpected type %s for target %s",
        unzipAarRule.getClass(),
        buildTarget);
    UnzipAar unzipAar = (UnzipAar) unzipAarRule;

    if (JavaAbis.isClassAbiTarget(buildTarget)) {
      return CalculateClassAbi.of(
          buildTarget,
          graphBuilder,
          projectFilesystem,
          ExplicitBuildTargetSourcePath.of(
              unzipAar.getBuildTarget(), unzipAar.getPathToClassesJar()));
    }

    Iterable<PrebuiltJar> javaDeps =
        Iterables.concat(
            Iterables.filter(graphBuilder.getAllRules(args.getDeps()), PrebuiltJar.class),
            Iterables.transform(
                Iterables.filter(
                    graphBuilder.getAllRules(args.getDeps()), AndroidPrebuiltAar.class),
                AndroidPrebuiltAar::getPrebuiltJar));

    if (flavors.contains(AAR_PREBUILT_JAR_FLAVOR)) {
      Preconditions.checkState(
          flavors.getSet().size() == 1,
          "Expected only flavor to be %s but also found %s",
          AAR_PREBUILT_JAR_FLAVOR,
          flavors);
      BuildRuleParams buildRuleParams =
          params
              .withDeclaredDeps(ImmutableSortedSet.copyOf(javaDeps))
              .withExtraDeps(ImmutableSortedSet.of(unzipAar));
      return new PrebuiltJar(
          buildTarget,
          projectFilesystem,
          /* params */ buildRuleParams,
          graphBuilder.getSourcePathResolver(),
          /* binaryJar */ ExplicitBuildTargetSourcePath.of(
              unzipAar.getBuildTarget(), unzipAar.getPathToClassesJar()),
          /* sourceJar */ Optional.empty(),
          /* gwtJar */ Optional.empty(),
          /* javadocUrl */ Optional.empty(),
          /* mavenCoords */ Optional.empty(),
          /* provided */ false,
          args.getRequiredForSourceOnlyAbi(),
          /* generate_abi */ true,
          /* neverMarkAsUnusedDependency */ false);
    }

    if (flavors.contains(AndroidResourceDescription.AAPT2_COMPILE_FLAVOR)) {
      AndroidPlatformTarget androidPlatformTarget =
          toolchainProvider.getByName(
              AndroidPlatformTarget.DEFAULT_NAME,
              buildTarget.getTargetConfiguration(),
              AndroidPlatformTarget.class);
      ToolProvider aapt2ToolProvider = androidPlatformTarget.getAapt2ToolProvider();

      return new Aapt2Compile(
          buildTarget,
          projectFilesystem,
          graphBuilder,
          aapt2ToolProvider.resolve(graphBuilder, buildTarget.getTargetConfiguration()),
          unzipAar.getResDirectory(),
          /* skipCrunchPngs */ false,
          androidBuckConfig.getFailOnLegacyAaptErrors());
    }

    BuildRule prebuiltJarRule =
        graphBuilder.requireRule(
            buildTarget.assertUnflavored().withFlavors(AAR_PREBUILT_JAR_FLAVOR));
    Preconditions.checkState(
        prebuiltJarRule instanceof PrebuiltJar,
        "%s flavor created rule of unexpected type %s for target %s",
        AAR_PREBUILT_JAR_FLAVOR,
        unzipAarRule.getType(),
        buildTarget);
    PrebuiltJar prebuiltJar = (PrebuiltJar) prebuiltJarRule;

    Preconditions.checkArgument(
        flavors.isEmpty(), "Unexpected flavors for android_prebuilt_aar: %s", flavors);

    BuildRuleParams androidLibraryParams =
        params
            .withDeclaredDeps(
                ImmutableSortedSet.copyOf(
                    Iterables.concat(javaDeps, Collections.singleton(prebuiltJar))))
            .withExtraDeps(ImmutableSortedSet.of(unzipAar));
    return new AndroidPrebuiltAar(
        buildTarget,
        projectFilesystem,
        androidLibraryParams,
        graphBuilder,
        /* proguardConfig */ ExplicitBuildTargetSourcePath.of(
            unzipAar.getBuildTarget(), unzipAar.getProguardConfig()),
        /* nativeLibsDirectory */ ExplicitBuildTargetSourcePath.of(
            unzipAar.getBuildTarget(), unzipAar.getNativeLibsDirectory()),
        /* prebuiltJar */ prebuiltJar,
        /* unzipRule */ unzipAar,
        new JavacToJarStepFactory(
            javacFactory.create(graphBuilder, null, buildTarget.getTargetConfiguration()),
            toolchainProvider
                .getByName(
                    JavacOptionsProvider.DEFAULT_NAME,
                    buildTarget.getTargetConfiguration(),
                    JavacOptionsProvider.class)
                .getJavacOptions(),
            ExtraClasspathProvider.EMPTY),
        /* exportedDeps */ javaDeps,
        args.getRequiredForSourceOnlyAbi(),
        args.getMavenCoords(),
        args.isUseSystemLibraryLoader());
  }

  @Override
  public void findDepsForTargetFromConstructorArgs(
      BuildTarget buildTarget,
      CellNameResolver cellRoots,
      AndroidPrebuiltAarDescriptionArg constructorArg,
      Builder<BuildTarget> extraDepsBuilder,
      Builder<BuildTarget> targetGraphOnlyDepsBuilder) {
    javacFactory.addParseTimeDeps(
        targetGraphOnlyDepsBuilder, null, buildTarget.getTargetConfiguration());
    AndroidTools.addParseTimeDepsToAndroidTools(
        toolchainProvider, buildTarget, targetGraphOnlyDepsBuilder);
  }

  @RuleArg
  interface AbstractAndroidPrebuiltAarDescriptionArg
      extends BuildRuleArg, HasDeclaredDeps, MaybeRequiredForSourceOnlyAbiArg {
    SourcePath getAar();

    Optional<SourcePath> getSourceJar();

    Optional<String> getJavadocUrl();

    Optional<String> getMavenCoords();

    @Override
    @Value.Default
    default boolean getRequiredForSourceOnlyAbi() {
      // Prebuilt jars are quick to build, and often contain third-party code, which in turn is
      // often a source of annotations and constants. To ease migration to ABI generation from
      // source without deps, we have them present during ABI gen by default.
      return true;
    }

    /**
     * If an AAR bundles a native .so as well as java code that uses System.loadLibrary() to
     * dynamically link this so, then we need to disable some optimizations for these libraries,
     * namely native exopackage code, SoMerge, and ReLinker
     */
    @Value.Default
    default boolean isUseSystemLibraryLoader() {
      return false;
    }
  }
}