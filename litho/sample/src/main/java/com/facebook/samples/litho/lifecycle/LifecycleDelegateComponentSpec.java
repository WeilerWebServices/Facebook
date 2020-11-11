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

package com.facebook.samples.litho.lifecycle;

import static com.facebook.samples.litho.lifecycle.LifecycleDelegateComponentSpec.DelegateListener.ON_ATTACHED;
import static com.facebook.samples.litho.lifecycle.LifecycleDelegateComponentSpec.DelegateListener.ON_CREATE_INITIAL_STATE;
import static com.facebook.samples.litho.lifecycle.LifecycleDelegateComponentSpec.DelegateListener.ON_CREATE_LAYOUT;
import static com.facebook.samples.litho.lifecycle.LifecycleDelegateComponentSpec.DelegateListener.ON_CREATE_TRANSITION;
import static com.facebook.samples.litho.lifecycle.LifecycleDelegateComponentSpec.DelegateListener.ON_CREATE_TREE_PROP;
import static com.facebook.samples.litho.lifecycle.LifecycleDelegateComponentSpec.DelegateListener.ON_DETACHED;

import android.graphics.Color;
import android.os.SystemClock;
import com.facebook.litho.ClickEvent;
import com.facebook.litho.Column;
import com.facebook.litho.Component;
import com.facebook.litho.ComponentContext;
import com.facebook.litho.EventHandler;
import com.facebook.litho.Row;
import com.facebook.litho.StateValue;
import com.facebook.litho.Transition;
import com.facebook.litho.annotations.LayoutSpec;
import com.facebook.litho.annotations.OnAttached;
import com.facebook.litho.annotations.OnCreateInitialState;
import com.facebook.litho.annotations.OnCreateLayout;
import com.facebook.litho.annotations.OnCreateTransition;
import com.facebook.litho.annotations.OnCreateTreeProp;
import com.facebook.litho.annotations.OnDetached;
import com.facebook.litho.annotations.OnEvent;
import com.facebook.litho.annotations.OnUpdateState;
import com.facebook.litho.annotations.Param;
import com.facebook.litho.annotations.Prop;
import com.facebook.litho.annotations.State;
import com.facebook.litho.widget.SolidColor;
import com.facebook.litho.widget.Text;
import com.facebook.yoga.YogaAlign;
import com.facebook.yoga.YogaEdge;
import java.util.Random;

@LayoutSpec
class LifecycleDelegateComponentSpec {

  private static final int[] COLORS = {
    Color.BLACK,
    Color.DKGRAY,
    Color.GRAY,
    Color.LTGRAY,
    Color.RED,
    Color.GREEN,
    Color.BLUE,
    Color.YELLOW,
    Color.CYAN,
    Color.MAGENTA
  };

  private static final DummyTreeProp sDummyTreeProp = new DummyTreeProp();

  interface DelegateListener {
    int ON_CREATE_INITIAL_STATE = 0;
    int ON_CREATE_TREE_PROP = 1;
    int ON_CREATE_LAYOUT = 2;
    int ON_CREATE_TRANSITION = 3;
    int ON_ATTACHED = 4;
    int ON_DETACHED = 5;

    void onDelegateMethodCalled(int type, Thread thread, long timestamp, int id);

    void setRootComponent(boolean isSync);
  }

  @OnCreateInitialState
  static void onCreateInitialState(
      ComponentContext c,
      StateValue<Random> random,
      StateValue<Integer> colorIndex,
      @Prop DelegateListener delegateListener,
      @Prop int id) {
    final Random rand = new Random();
    random.set(rand);
    colorIndex.set(rand.nextInt(COLORS.length));
    onDelegateMethodCalled(delegateListener, ON_CREATE_INITIAL_STATE, id);
  }

  @OnCreateTreeProp
  static DummyTreeProp onCreateTreeProp(
      ComponentContext c, @Prop DelegateListener delegateListener, @Prop int id) {
    onDelegateMethodCalled(delegateListener, ON_CREATE_TREE_PROP, id);
    return sDummyTreeProp;
  }

  @OnCreateLayout
  static Component onCreateLayout(
      ComponentContext c,
      @Prop DelegateListener delegateListener,
      @Prop int id,
      @State Integer colorIndex) {
    onDelegateMethodCalled(delegateListener, ON_CREATE_LAYOUT, id);

    return Column.create(c).child(buttons(c)).child(bricks(c, colorIndex)).build();
  }

  @OnCreateTransition
  static Transition onCreateTransition(
      ComponentContext c, @Prop DelegateListener delegateListener, @Prop int id) {
    onDelegateMethodCalled(delegateListener, ON_CREATE_TRANSITION, id);
    return Transition.allLayout().animator(Transition.SPRING_WITH_OVERSHOOT);
  }

  @OnAttached
  static void onAttached(
      ComponentContext c, @Prop DelegateListener delegateListener, @Prop int id) {
    onDelegateMethodCalled(delegateListener, ON_ATTACHED, id);
  }

  @OnDetached
  static void onDetached(
      ComponentContext c, @Prop DelegateListener delegateListener, @Prop int id) {
    onDelegateMethodCalled(delegateListener, ON_DETACHED, id);
  }

  @OnUpdateState
  static void updateBricks(StateValue<Integer> colorIndex, @Param Random rand) {
    colorIndex.set(rand.nextInt(COLORS.length));
  }

  @OnEvent(ClickEvent.class)
  static void onClickStateUpdate(ComponentContext c, @State Random random, @Param boolean isSync) {
    if (isSync) {
      LifecycleDelegateComponent.updateBricksSync(c, random);
    } else {
      LifecycleDelegateComponent.updateBricksAsync(c, random);
    }
  }

  @OnEvent(ClickEvent.class)
  static void onClickResetRootComponent(
      ComponentContext c, @Prop DelegateListener delegateListener, @Param boolean isSync) {
    delegateListener.setRootComponent(isSync);
  }

  private static Component button(
      ComponentContext c, String text, EventHandler<ClickEvent> handler) {
    return Row.create(c, android.R.attr.buttonStyle, 0)
        .clickHandler(handler)
        .child(Text.create(c).text(text).alignSelf(YogaAlign.CENTER))
        .build();
  }

  private static Component buttons(ComponentContext c) {
    return Column.create(c)
        .child(
            Row.create(c)
                .child(
                    button(
                        c,
                        "Sync State Update",
                        LifecycleDelegateComponent.onClickStateUpdate(c, true)))
                .child(
                    button(
                        c,
                        "Async State Update",
                        LifecycleDelegateComponent.onClickStateUpdate(c, false))))
        .child(
            Row.create(c)
                .child(
                    button(
                        c,
                        "Sync Set Root Component",
                        LifecycleDelegateComponent.onClickResetRootComponent(c, true)))
                .child(
                    button(
                        c,
                        "Async Set Root Component",
                        LifecycleDelegateComponent.onClickResetRootComponent(c, false))))
        .build();
  }

  private static Component bricks(ComponentContext c, int colorIndex) {
    return Column.create(c)
        .marginDip(YogaEdge.ALL, 4)
        .child(
            Row.create(c)
                .child(
                    SolidColor.create(c)
                        .color(COLORS[colorIndex])
                        .paddingDip(YogaEdge.ALL, 4)
                        .widthDip(100)
                        .heightDip(100))
                .child(
                    SolidColor.create(c)
                        .color(COLORS[(colorIndex + 1) % COLORS.length])
                        .paddingDip(YogaEdge.ALL, 4)
                        .widthDip(100)
                        .heightDip(100)))
        .child(
            Row.create(c)
                .child(
                    SolidColor.create(c)
                        .color(COLORS[(colorIndex + 2) % COLORS.length])
                        .paddingDip(YogaEdge.ALL, 4)
                        .widthDip(100)
                        .heightDip(100))
                .child(
                    SolidColor.create(c)
                        .color(COLORS[(colorIndex + 3) % COLORS.length])
                        .paddingDip(YogaEdge.ALL, 4)
                        .widthDip(100)
                        .heightDip(100)))
        .build();
  }

  private static void onDelegateMethodCalled(DelegateListener delegateListener, int type, int id) {
    delegateListener.onDelegateMethodCalled(
        type, Thread.currentThread(), SystemClock.elapsedRealtime(), id);
  }

  static class DummyTreeProp {}
}
