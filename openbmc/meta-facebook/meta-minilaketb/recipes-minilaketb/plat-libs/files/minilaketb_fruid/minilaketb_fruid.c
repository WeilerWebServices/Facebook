/* Copyright 2015-present Facebook. All Rights Reserved.
 *
 * This file contains code to support IPMI2.0 Specificaton available @
 * http://www.intel.com/content/www/us/en/servers/ipmi/ipmi-specifications.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <syslog.h>
#include "minilaketb_fruid.h"

#define NIC_FW_VER_PATH "/tmp/cache_store/nic_fw_ver"

static int
plat_get_ipmb_bus_id(uint8_t slot_id) {
  int bus_id;

  switch(slot_id) {
  case FRU_SLOT1:
    bus_id = IPMB_BUS_SLOT1;
    break;
  default:
    bus_id = -1;
    break;
  }

  return bus_id;
}


/* Populate char path[] with the path to the fru's fruid binary dump */
int
minilaketb_get_fruid_path(uint8_t fru, char *path) {
  char fname[16] = {0};

  switch(fru) {
    case FRU_SLOT1:
      sprintf(fname, "slot1");
      break;
    case FRU_SPB:
      sprintf(fname, "spb");
      break;

    default:
#ifdef DEBUG
      syslog(LOG_WARNING, "minilaketb_get_fruid_path: wrong fruid");
#endif
      return -1;
  }

  sprintf(path, MINILAKETB_FRU_PATH, fname);
  return 0;
}

int
minilaketb_get_fruid_eeprom_path(uint8_t fru, char *path) {
  char fname[16] = {0};

  switch(fru) {
    case FRU_SLOT1:
      switch(minilaketb_get_slot_type(fru))
      {
        case SLOT_TYPE_SERVER:
        case SLOT_TYPE_NULL:
          return -1;
          break;
        case SLOT_TYPE_CF:
        case SLOT_TYPE_GP:
          sprintf(path, "/sys/class/i2c-adapter/i2c-%d/%d-0051/eeprom",plat_get_ipmb_bus_id(fru),plat_get_ipmb_bus_id(fru));
          break;
      }
      break;
    case FRU_SPB:
      sprintf(path, "/sys/class/i2c-adapter/i2c-8/8-0051/eeprom");
      break;

    default:
#ifdef DEBUG
      syslog(LOG_WARNING, "minilaketb_get_fruid_eeprom_path: wrong fruid");
#endif
      return -1;
  }

  return 0;
}

/* Populate char name[] with the path to the fru's name */
int
minilaketb_get_fruid_name(uint8_t fru, char *name) {
  uint32_t mfg_id;

  switch(fru) {
    case FRU_SLOT1:
      switch(minilaketb_get_slot_type(fru))
      {
        case SLOT_TYPE_SERVER:
          sprintf(name, "Server Board %d",fru);
          break;
        case SLOT_TYPE_CF:
          sprintf(name, "Crane Flat %d",fru);
          break;
        case SLOT_TYPE_GP:
          sprintf(name, "Glacier Point %d",fru);
          break;
        case SLOT_TYPE_NULL:
          sprintf(name, "Empty SLOT %d",fru);
          break;
      }
      break;
    case FRU_SPB:
      sprintf(name, "Side Plane Board");
      break;

    default:
#ifdef DEBUG
      syslog(LOG_WARNING, "minilaketb_get_fruid_name: wrong fruid");
#endif
      return -1;
  }
  return 0;
}