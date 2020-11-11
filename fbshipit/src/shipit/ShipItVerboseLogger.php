<?hh // strict
/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

namespace Facebook\ShipIt;

use namespace HH\Lib\Str;

final class ShipItVerboseLogger {
  public function __construct(private bool $verbose) {
  }

  public function out(Str\SprintfFormatString $f, mixed ...$args): void {
    ShipItLogger::out(
      "%s%s\n",
      /* HH_IGNORE_ERROR[2049] __PHPStdLib */
      /* HH_IGNORE_ERROR[4107] __PHPStdLib */
      $this->verbose ? '['.\date('H:i:s').'] ' : '',
      /* HH_IGNORE_ERROR[2049] __PHPStdLib */
      /* HH_IGNORE_ERROR[4107] __PHPStdLib */
      \vsprintf($f, $args) as string,
    );
  }

  public function err(Str\SprintfFormatString $f, mixed ...$args): void {
    ShipItLogger::err(
      "%s%s\n",
      /* HH_IGNORE_ERROR[2049] __PHPStdLib */
      /* HH_IGNORE_ERROR[4107] __PHPStdLib */
      $this->verbose ? '['.\date('H:i:s').'] ' : '',
      /* HH_IGNORE_ERROR[2049] __PHPStdLib */
      /* HH_IGNORE_ERROR[4107] __PHPStdLib */
      \vsprintf($f, $args) as string,
    );
  }
}
