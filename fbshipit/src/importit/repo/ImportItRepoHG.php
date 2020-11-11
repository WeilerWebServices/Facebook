<?hh // strict
/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

/**
 * This file was moved from fbsource to www. View old history in diffusion:
 * https://fburl.com/dmdflevr
 */
namespace Facebook\ImportIt;

/**
 * Specialization of ShipItRepoHG
 */
final class ImportItRepoHG extends \Facebook\ShipIt\ShipItRepoHG {
  <<__Override>>
  public function setBranch(string $branch): bool {
    // This class creates a bookmark and uses it to keep track of where it is.
    // So if $branch is `master`, that can cause trouble. Easiest solution is
    // to alphavary the name.
    return parent::setBranch($branch."_importit");
  }
}
