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

package com.facebook.litho.widget;

import android.content.Context;
import android.view.View;
import androidx.annotation.UiThread;
import com.facebook.litho.ComponentContext;
import com.facebook.litho.ComponentLayout;
import com.facebook.litho.LifecycleStep;
import com.facebook.litho.Size;
import com.facebook.litho.TestTriggerEvent;
import com.facebook.litho.annotations.FromTrigger;
import com.facebook.litho.annotations.MountSpec;
import com.facebook.litho.annotations.OnCreateMountContent;
import com.facebook.litho.annotations.OnMeasure;
import com.facebook.litho.annotations.OnPrepare;
import com.facebook.litho.annotations.OnTrigger;
import com.facebook.litho.annotations.Prop;
import java.util.List;
import java.util.concurrent.atomic.AtomicReference;

@MountSpec
class MountSpecTriggerTesterSpec {
  @OnPrepare
  static void onPrepare(ComponentContext c) {}

  @OnMeasure
  static void onMeasure(
      ComponentContext context, ComponentLayout layout, int widthSpec, int heightSpec, Size size) {
    size.width = 600;
    size.height = 800;
  }

  @UiThread
  @OnCreateMountContent
  static View onCreateMountContent(Context c) {
    return new View(c);
  }

  @OnTrigger(TestTriggerEvent.class)
  static void triggerTestEvent(
      ComponentContext c,
      @Prop List<LifecycleStep.StepInfo> steps,
      @Prop AtomicReference<Object> triggerObjectRef,
      @FromTrigger Object triggerObject) {
    steps.add(new LifecycleStep.StepInfo(LifecycleStep.ON_TRIGGER));
    triggerObjectRef.set(triggerObject);
  }
}
