#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <fcntl.h>
#include <errno.h>
#include <syslog.h>
#include <sys/mman.h>
#include <string.h>
#include <ctype.h>
#include <openbmc/kv.h>
#include <openbmc/obmc-i2c.h>
#include <openbmc/libgpio.h>
#include "pal.h"
#include "pal_sbmc.h"

#define GPIO_POWER "FM_BMC_PWRBTN_OUT_R_N"
#define GPIO_POWER_GOOD "PWRGD_SYS_PWROK"
#define GPIO_CPU0_POWER_GOOD "PWRGD_CPU0_LVC3"
#define GPIO_POWER_RESET "RST_BMC_RSTBTN_OUT_R_N"
#define GPIO_RESET_BTN_IN "FP_BMC_RST_BTN_N"

#define DELAY_POWER_ON 1
#define DELAY_POWER_OFF 6
#define DELAY_GRACEFUL_SHUTDOWN 1
#define DELAY_POWER_CYCLE 10

bool
is_server_off(void) {
  int ret;
  uint8_t status;

  ret = pal_get_server_power(FRU_MB, &status);
  if (ret) {
    return false;
  }

  return status == SERVER_POWER_OFF? true: false;
}

static int
power_btn_out_pulse(uint8_t secs) {
  int ret = 0;
  gpio_desc_t *gdesc;

  gdesc = gpio_open_by_shadow(GPIO_POWER);
  if (!gdesc)
    return -1;

  do {
    ret = gpio_set_value(gdesc, GPIO_VALUE_HIGH);
    if (ret)
      break;

    ret = gpio_set_value(gdesc, GPIO_VALUE_LOW);
    if (ret)
      break;

    sleep(secs);

    ret = gpio_set_value(gdesc, GPIO_VALUE_HIGH);
  } while (0);

  gpio_close(gdesc);
  return ret;
}

// Power Off the server
static int
server_power_off(bool gs_flag) {
  return power_btn_out_pulse((gs_flag) ? DELAY_GRACEFUL_SHUTDOWN : DELAY_POWER_OFF);
}

// Power On the server
static int
server_power_on(void) {
  return power_btn_out_pulse(DELAY_POWER_ON);
}

int
pal_power_button_override(uint8_t fru_id) {
  return power_btn_out_pulse(DELAY_POWER_OFF);
}

int
pal_get_server_power(uint8_t fru, uint8_t *status) {
  int ret;
  gpio_desc_t *gdesc = NULL;
  gpio_value_t val;

  if (fru != FRU_MB)
    return -1;

  gdesc = gpio_open_by_shadow(GPIO_CPU0_POWER_GOOD);
  if (gdesc == NULL)
    return -1;

  ret = gpio_get_value(gdesc, &val);
  if (ret != 0)
    goto error;

  *status = (int)val;
error:
  gpio_close(gdesc);
  return ret;
}

// Power Off, Power On, or Power Reset the server in given slot
int
pal_set_server_power(uint8_t fru, uint8_t cmd) {
  uint8_t status;
  bool gs_flag = false;
  uint8_t ret;

  if (pal_get_server_power(fru, &status) < 0) {
    return -1;
  }

  switch(cmd) {
    case SERVER_POWER_ON:
      if (status == SERVER_POWER_ON)
        return 1;
      else
        return server_power_on();
      break;

    case SERVER_POWER_OFF:
      if (status == SERVER_POWER_OFF)
        return 1;
      else
        return server_power_off(gs_flag);
      break;

    case SERVER_POWER_CYCLE:
      if (status == SERVER_POWER_ON) {
        if (server_power_off(gs_flag))
          return -1;

        sleep(DELAY_POWER_CYCLE);

        return server_power_on();

      } else if (status == SERVER_POWER_OFF) {

        return (server_power_on());
      }
      break;

    case SERVER_GRACEFUL_SHUTDOWN:
      if (status == SERVER_POWER_OFF)
        return 1;
      gs_flag = true;
      return server_power_off(gs_flag);
      break;

   case SERVER_POWER_RESET:
      if (status == SERVER_POWER_ON) {
        ret = pal_set_rst_btn(fru, 0);
        if (ret < 0)
          return ret;
        msleep(100); //some server miss to detect a quick pulse, so delay 100ms between low high
        ret = pal_set_rst_btn(fru, 1);
        if (ret < 0)
          return ret;
      } else if (status == SERVER_POWER_OFF)
        return -1;
      break;

    default:
      return -1;
  }

  return 0;
}

int
pal_sled_cycle(void) {

  // If JBOG is present, request power cycle
  // TODO:
  //      Add common interface for different JBOG platform

  if(is_ep_present()) {
    if (pal_ep_sled_cycle() < 0) {
      syslog(LOG_ERR, "Request JBOG power-cycle failed");
    }
  }

  if(is_cc_present()) {
    if (pal_cc_sled_cycle() < 0) {
      syslog(LOG_ERR, "Request JBOG power-cycle failed");
    }
  }

  // Send command to HSC power cycle
  if( lib_cmc_power_cycle() ) {
    return -1;
  }
  return 0;
}

// Return the front panel's Reset Button status
int
pal_get_rst_btn(uint8_t *status) {
  int ret = -1;
  gpio_value_t value;
  gpio_desc_t *desc = gpio_open_by_shadow(GPIO_RESET_BTN_IN);
  if (!desc) {
    return -1;
  }
  if (0 == gpio_get_value(desc, &value)) {
    *status = value == GPIO_VALUE_HIGH ? 0 : 1;
    ret = 0;
  }
  gpio_close(desc);
  return ret;
}

int
pal_set_rst_btn(uint8_t slot, uint8_t status) {
  int ret;
  gpio_desc_t *gdesc = NULL;
  gpio_value_t val;

  if (slot != FRU_MB) {
    return -1;
  }

  gdesc = gpio_open_by_shadow(GPIO_POWER_RESET);
  if (gdesc == NULL)
    return -1;

  val = status? GPIO_VALUE_HIGH: GPIO_VALUE_LOW;
  ret = gpio_set_value(gdesc, val);
  if (ret != 0)
    goto error;

error:
  gpio_close(gdesc);
  return ret;
}

int
pal_set_last_pwr_state(uint8_t fru, char *state) {

  int ret;
  char key[MAX_KEY_LEN] = {0};

  sprintf(key, "%s", "pwr_server_last_state");

  ret = pal_set_key_value(key, state);
  if (ret < 0) {
#ifdef DEBUG
    syslog(LOG_WARNING, "pal_set_last_pwr_state: pal_set_key_value failed for "
        "fru %u", fru);
#endif
  }

  return ret;
}

int
pal_get_last_pwr_state(uint8_t fru, char *state) {
  int ret;
  char key[MAX_KEY_LEN] = {0};

  sprintf(key, "%s", "pwr_server_last_state");

  ret = pal_get_key_value(key, state);
  if (ret < 0) {
#ifdef DEBUG
    syslog(LOG_WARNING, "pal_get_last_pwr_state: pal_get_key_value failed for "
        "fru %u", fru);
#endif
  }

  return ret;
}

uint8_t
pal_set_power_restore_policy(uint8_t slot, uint8_t *pwr_policy, uint8_t *res_data) {
  int cc = CC_SUCCESS;  // Fill response with default values
  int i=0;
  int ret;
  uint8_t policy = *pwr_policy & 0x07;  // Power restore policy
  uint8_t mode;

  switch (policy) {
    case 0:
      if (pal_set_key_value("server_por_cfg", "off") != 0)
        cc = CC_UNSPECIFIED_ERROR;
      break;
    case 1:
      if (pal_set_key_value("server_por_cfg", "lps") != 0)
        cc = CC_UNSPECIFIED_ERROR;
      break;
    case 2:
      if (pal_set_key_value("server_por_cfg", "on") != 0)
        cc = CC_UNSPECIFIED_ERROR;
      break;
    case 3:
      // no change (just get present policy support)
      break;
    default:
      cc = CC_PARAM_OUT_OF_RANGE;
      break;
  }

  ret = pal_get_host_system_mode(&mode);
  if(ret != 0) {
    return ret;
  }

  if(mode == MB_4S_MODE) {
    ret = pal_get_config_is_master(); 
    if(ret == false) {
      return CC_OEM_ONLY_SUPPORT_MASTER;
    } else {
      if( cmd_set_smbc_restore_power_policy(policy, BMC1_SLAVE_DEF_ADDR) ) {
        return CC_OEM_DEVICE_SEND_SLAVE_RESTORE_POWER_POLICY_FAIL;
      }
    }
  }  
  return cc;
}

void
pal_set_def_restart_cause(uint8_t slot)
{
  char pwr_policy[MAX_VALUE_LEN] = {0};
  char last_pwr_st[MAX_VALUE_LEN] = {0};
  if ( FRU_MB == slot )
  {
    kv_get("pwr_server_last_state", last_pwr_st, NULL, KV_FPERSIST);
    kv_get("server_por_cfg", pwr_policy, NULL, KV_FPERSIST);
    if( pal_is_bmc_por() )
    {
      if( !strcmp( pwr_policy, "on") )
      {
        pal_set_restart_cause(FRU_MB, RESTART_CAUSE_AUTOMATIC_PWR_UP);
      }
      else if( !strcmp( pwr_policy, "lps") && !strcmp( last_pwr_st, "on") )
      {
        pal_set_restart_cause(FRU_MB, RESTART_CAUSE_AUTOMATIC_PWR_UP_LPR);
      }
    }
  }
}

static
int pal_get_cpld_power_sts(uint8_t *state)
{
  int fd = 0;
  char fn[32];
  uint8_t tbuf[16] = {0};
  int ret = 0;

  snprintf(fn, sizeof(fn), "/dev/i2c-%d", MAIN_CPLD_BUS_ID);
  fd = open(fn, O_RDWR);
  if (fd < 0) {
    syslog(LOG_WARNING, "[%s] Cannot open the i2c-%d", __func__, MAIN_CPLD_BUS_ID);
    ret = -1;
    goto exit;
  }

  // Get the data offset 0x00 0x03
  tbuf[0] = (MAIN_CPLD_PWR_STATE_CMD >> 8);
  tbuf[1] = (MAIN_CPLD_PWR_STATE_CMD & 0x00FF);

  ret = i2c_rdwr_msg_transfer(fd, MAIN_CPLD_PWR_STATE_ADDR, tbuf, 2, state, 1);
  if (ret < 0) {
    syslog(LOG_WARNING, "[%s] Cannot acces the i2c-%d dev: %x",
           __func__, MAIN_CPLD_BUS_ID, MAIN_CPLD_PWR_STATE_ADDR);
    ret = -1;
    goto exit;
  }

  ret = PAL_EOK;

exit:
  if (fd > 0)
    close(fd);

  return ret;
}

static 
void print_power_fail_log(uint8_t cpu_num, uint8_t cpu_sts) 
{
  const char* cpld_power_seq[] = {
    "Reserve",
    "CPLD_PWR_CPU_FAULT",
    "CPLD_PWR_CPU_OFF",
    "CPLD_PWR_CPU_PVCCIO",
    "CPLD_PWR_P1V8_PCIE_P1V1",
    "Reserve",
    "CPLD_PWR_PVCCIN",
    "CPLD_PWR_PVCCSA",       
    "CPLD_PWR_CPU_DONE",
    "CPLD_PWR_PVCCSA_OFF",
    "CPLD_PWR_PVCCIN_OFF",
    "Reserve", 
    "CPLD_PWR_P1V8_PCIE_P1V1_OFF",
    "CPLD_PWR_PVCCIO_OFF",
  };

  if(strcmp(cpld_power_seq[cpu_sts], "Reserve") != 0) {
    syslog(LOG_CRIT, "ASSERT: CPU%d %s power rail fails discrete - FRU: %d", 
           cpu_num, cpld_power_seq[cpu_sts], FRU_MB);

  }
}

int pal_check_cpld_power_fail(void)
{
  uint8_t pwr_st;
  uint8_t cpu0_st, cpu1_st=0;
  uint8_t cpu0_prsnt, cpu1_prsnt;
  uint8_t pwr_off;

  pwr_off = is_server_off();
 
  if( pal_get_cpld_power_sts(&pwr_st) ) {
    return -1;
  }
  cpu0_st = (pwr_st & 0xf0) >> 4;
  cpu1_st = (pwr_st & 0x0f); 
  cpu0_prsnt = check_cpu_present_pin_gpio(CPU_ID0);
  cpu1_prsnt = check_cpu_present_pin_gpio(CPU_ID1);  

//Check Power On
  if( pwr_off == false) {
    if(cpu0_st != CPLD_PWR_CPU_DOWN && cpu0_prsnt == 0) {
      print_power_fail_log(CPU_ID0, cpu0_st);
    }

    if(cpu1_st != CPLD_PWR_CPU_DOWN && cpu1_prsnt == 0) {
      print_power_fail_log(CPU_ID1, cpu1_st);
    }
//Check Power Off
  } else {
    if(cpu0_st != CPLD_PWR_CPU_OFF && cpu0_prsnt == 0) {
      print_power_fail_log(CPU_ID0, cpu0_st);
    }

    if(cpu1_st != CPLD_PWR_CPU_OFF && cpu1_prsnt == 0) {
      print_power_fail_log(CPU_ID1, cpu1_st);
    }
  }
 
  return 0; 
}
