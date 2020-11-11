/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

package redex;

import static org.fest.assertions.api.Assertions.assertThat;

import org.junit.Test;

interface IA {
  public int do_something();
}

abstract class BB implements IA {
  public BB return_self() { return this; }
}

class CC extends BB {
  // PRECHECK: method: virtual redex.CC.do_something
  // POSTCHECK: method: virtual redex.CC.do_something
  public int do_something() { return 1; }

  @Override
  public BB return_self() {
    return this;
  }
}

class D extends BB {
  // PRECHECK: method: virtual redex.D.do_something
  // POSTCHECK: method: virtual redex.D.do_something
  public int do_something() { return 2; }
}

interface IE {
  public int do_something();
}

abstract class F implements IE {}

class G extends F {
  // PRECHECK: method: virtual redex.G.do_something
  // POSTCHECK-NOT: method: virtual redex.G.do_something
  public int do_something() { return 3; }
}

class H extends F {
  // PRECHECK: method: virtual redex.H.do_something
  // POSTCHECK-NOT: method: virtual redex.H.do_something
  public int do_something() { return 4; }
}

interface IGetInt {
  public int getInt();
  public int getAnotherInt();
}

abstract class GetInt implements IGetInt {}

class GetInt1 extends GetInt {
  // CHECK: method: virtual redex.GetInt1.getAnotherInt
  public int getAnotherInt() { return 2; }

  // PRECHECK: method: virtual redex.GetInt1.getInt
  // POSTCHECK-NOT: method: virtual redex.GetInt1.getInt
  public int getInt() { return 1; }
}

class GetInt2 extends GetInt {
  // CHECK: method: virtual redex.GetInt2.getAnotherInt
  public int getAnotherInt() { return 3; }

  // PRECHECK: method: virtual redex.GetInt2.getInt
  // POSTCHECK-NOT: method: virtual redex.GetInt2.getInt
  public int getInt() { return 1; }
}

class GetInt3 extends GetInt {
  // CHECK: method: virtual redex.GetInt3.getAnotherInt
  public int getAnotherInt() { return 4; }

  // PRECHECK: method: virtual redex.GetInt3.getInt
  // POSTCHECK-NOT: method: virtual redex.GetInt3.getInt
  public int getInt() { return 1; }
}

class SameImplementation {
  // PRECHECK: method: virtual redex.SameImplementation.getInt
  // POSTCHECK-NOT: method: virtual redex.SameImplementation.getInt
  public int getInt() { return 1; }
}

class SameImplementation2 extends SameImplementation {
  // PRECHECK: method: virtual redex.SameImplementation2.getInt
  // POSTCHECK-NOT: method: virtual redex.SameImplementation2.getInt
  @Override
  public int getInt() {
    return 1;
  }
}

public class TrueVirtualInlineTest {

  // CHECK: method: virtual redex.TrueVirtualInlineTest.test_do_something
  @Test
  public void test_do_something() {
    CC c = new CC();
    // PRECHECK: invoke-virtual {{.*}} redex.CC.do_something
    // POSTCHECK-NOT: invoke-virtual {{.*}} redex.CC.do_something
    assertThat(c.do_something()).isEqualTo(1);

    H h = new H();
    // PRECHECK: invoke-virtual {{.*}} redex.H.do_something
    // POSTCHECK-NOT: invoke-virtual {{.*}} redex.H.do_something
    assertThat(h.do_something()).isEqualTo(4);

    BB b;
    if (Math.random() > 1) {
      b = new CC();
    } else {
      b = new D();
    }

    // PRECHECK: invoke-virtual {{.*}} redex.BB.do_something
    // POSTCHECK: invoke-virtual {{.*}} redex.BB.do_something
    assertThat(b.do_something()).isEqualTo(2);

    IA a = new CC();
    // PRECHECK: invoke-interface {{.*}} redex.IA.do_something
    // POSTCHECK: invoke-interface {{.*}} redex.IA.do_something
    assertThat(a.do_something()).isEqualTo(1);
    // CHECK: return-void
  }

  // CHECK: method: virtual redex.TrueVirtualInlineTest.test_return_self
  @Test
  public void test_return_self() {
    CC c = new CC();
    // PRECHECK: invoke-virtual {{.*}} redex.CC.return_self
    // POSTCHECK: invoke-virtual {{.*}} redex.CC.return_self
    assertThat(c.return_self() instanceof CC).isTrue();
    // CHECK: return-void
  }

  // CHECK: method: virtual redex.TrueVirtualInlineTest.test_same_implementation
  @Test
  public void test_same_implementation() {
    GetInt get_int;
    if (Math.random() > 1) {
      get_int = new GetInt1();
    } else if (Math.random() < 0) {
      get_int = new GetInt3();
    } else {
      // get_int should be of type GetInt2
      get_int = new GetInt2();
    }

    // PRECHECK: invoke-virtual {{.*}} redex.GetInt.getInt
    // POSTCHECK-NOT: invoke-virtual {{.*}} redex.GetInt.getInt
    assertThat(get_int.getInt()).isEqualTo(1);

    // PRECHECK: invoke-virtual {{.*}} redex.GetInt.getAnotherInt
    // POSTCHECK: invoke-virtual {{.*}} redex.GetInt.getAnotherInt
    assertThat(get_int.getAnotherInt()).isEqualTo(3);
    // CHECK: return-void
  }

  // CHECK: method: virtual redex.TrueVirtualInlineTest.test_same_implementation
  @Test
  public void test_same_implementation2() {
    SameImplementation get_int;
    if (Math.random() > 0.5) {
      get_int = new SameImplementation();
    } else {
      get_int = new SameImplementation2();
    }

    // PRECHECK: invoke-virtual {{.*}} redex.SameImplementation.getInt
    // POSTCHECK-NOT: invoke-virtual {{.*}} redex.SameImplementation.getInt
    assertThat(get_int.getInt()).isEqualTo(1);
    // CHECK: return-void
  }
}
