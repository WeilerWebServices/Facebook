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

import com.facebook.litho.Component;
import com.facebook.litho.ComponentContext;
import com.facebook.litho.StateCaller;
import com.facebook.litho.StateValue;
import com.facebook.litho.Transition;
import com.facebook.litho.annotations.LayoutSpec;
import com.facebook.litho.annotations.OnCreateInitialState;
import com.facebook.litho.annotations.OnCreateLayout;
import com.facebook.litho.annotations.OnCreateTransition;
import com.facebook.litho.annotations.OnUpdateState;
import com.facebook.litho.annotations.Prop;
import com.facebook.litho.annotations.State;

@LayoutSpec
public class TestAnimationsComponentSpec {
  public interface TestComponent {
    Component getComponent(ComponentContext componentContext, boolean state);
  }

  @OnCreateInitialState
  static void onCreateInitialState(
      final ComponentContext c, StateValue<Boolean> state, @Prop StateCaller stateCaller) {
    stateCaller.setStateUpdateListener(
        new StateCaller.StateUpdateListener() {
          @Override
          public void update() {
            TestAnimationsComponent.updateStateSync(c);
          }
        });
    state.set(false);
  }

  @OnCreateLayout
  static Component onCreateLayout(
      final ComponentContext c, @Prop TestComponent testComponent, @State boolean state) {
    return testComponent.getComponent(c, state);
  }

  @OnUpdateState
  static void updateState(StateValue<Boolean> state) {
    state.set(!state.get());
  }

  @OnCreateTransition
  static Transition onCreateTransition(ComponentContext c, @Prop Transition transition) {
    return transition;
  }
}
