#define EXP_ERROR_CODE_NUM		100
#define BMC_ERROR_CODE_NUM		100
#define BMC_ERROR_CODE_START	0xA0

char *Expander_Error_Code_Description[EXP_ERROR_CODE_NUM] = {
	"No error", //Error Code 0
	"Expander I2C bus 0 crash",
	"Expander I2C bus 1 crash",
	"Expander I2C bus 2 crash",
	"Expander I2C bus 3 crash",
	"Expander I2C bus 4 crash",
	"Expander I2C bus 5 crash",
	"Expander I2C bus 6 crash",
	"Expander I2C bus 7 crash",
	"Expander I2C bus 8 crash",
	"Expander I2C bus 9 crash",
	"Expander I2C bus 10 crash",
	"Expander I2C bus 11 crash",
	"Fan 1 front fault",
	"Fan 1 rear fault",
	"Fan 2 front fault",
	"Fan 2 rear fault",
	"Fan 3 front fault",
	"Fan 3 rear fault",
	"Fan 4 front fault",
	"Fan 4 rear fault",
	"SCC voltage warning",
	"DPB voltage warning",
	"Reserved",
	"Reserved",
	"SCC current warning",
	"DPB current warning",
	"SCC_I2C_device_loss",
	"DPB_I2C_device_loss",
	"DPB_Temp1",
	"DPB_Temp2",
	"SCC_Expander_Temp",
	"SCC_IOC_Temp",
	"HDD X SMART temp. warning",
	"Front_Panel_I2C_device_loss",
	"Reserved",
	"HDD0 fault",
	"HDD1 fault",
	"HDD2 fault",
	"HDD3 fault",
	"HDD4 fault",
	"HDD5 fault",
	"HDD6 fault",
	"HDD7 fault",
	"HDD8 fault",
	"HDD9 fault",
	"HDD10 fault",
	"HDD11 fault",
	"HDD12 fault",
	"HDD13 fault",
	"HDD14 fault",
	"HDD15 fault",
	"HDD16 fault",
	"HDD17 fault",
	"HDD18 fault",
	"HDD19 fault",
	"HDD20 fault",
	"HDD21 fault",
	"HDD22 fault",
	"HDD23 fault",
	"HDD24 fault",
	"HDD25 fault",
	"HDD26 fault",
	"HDD27 fault",
	"HDD28 fault",
	"HDD29 fault",
	"HDD30 fault",
	"HDD31 fault",
	"HDD32 fault",
	"HDD33 fault",
	"HDD34 fault",
	"HDD35 fault",
	"HDD X fault sensed",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Fan1 Plug Out",
	"Fan2 Plug Out",
	"Fan3 Plug Out",
	"Fan4 Plug Out",
	"Internal Mini-SAS link error",
	"Internal Mini-SAS link error",
	"Drawer be pulled out",
	"Peer SCC be plug out",
	"IOMA be plug out",
	"IOMB be plug out",
	"Reserved",
	"Reserved",
	"Reserved",
	"H/W Configuration/Type Not Match" //Error Code 99
};

char *BMC_Error_Code_Description[BMC_ERROR_CODE_NUM] = {
	"Reserved for BMC sensor",	//Error Code 0xA0
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"Reserved for BMC sensor",
	"BMC CPU Utilization too high",
	"BMC Memory Utilization too high",
	"ECC Recoverable Error",
	"ECC Uncecoverable Error",
	"Mono Lake Missing",		//Error Code 0xE4
	"Reserved",
	"Reserved",
	"SCC Missing",
	"NIC is plugged out",
	"BMC I2C bus 0 hang",
	"BMC I2C bus 1 hang",
	"BMC I2C bus 2 hang",
	"BMC I2C bus 3 hang",
	"BMC I2C bus 4 hang",
	"BMC I2C bus 5 hang",
	"BMC I2C bus 6 hang",
	"BMC I2C bus 7 hang",
	"BMC I2C bus 8 hang",
	"BMC I2C bus 9 hang",
	"BMC I2C bus 10 hang",
	"BMC I2C bus 11 hang",
	"BMC I2C bus 12 hang",
	"BMC I2C bus 13 hang",
	"Server sensor health is bad",
	"IOM sensor health is bad",
	"DPB sensor health is bad",
	"SCC sensor health is bad",
	"NIC sensor health is bad",
	"BMC remote heartbeat is abnormal",
	"SCC local heartbeat is abnormal",
	"SCC remote heartbeat is abnormal",
	"Reserved",
};