<?hh
// Copyright (c) Facebook, Inc. and its affiliates. All Rights Reserved.
<<file: __EnableUnstableFeatures('enum_class', 'enum_supertyping')>>

interface ExBox {}

class Box<T> implements ExBox {
  public function __construct(public T $data) {}
}

class IBox extends Box<int> {
  public function add(int $x): void {
    $this->data = $this->data + $x;
  }
}

enum class E: ExBox {
  A<Box<string>>(new Box('zuck'));
  B<IBox>(new IBox(42));
}

enum NormalEnum : int includes E {
  Z = 42;
}
