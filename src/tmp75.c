
#include "tmp75.h"
#include "i2c.h"
#include "sched.h"
#include <stdio.h>

#define TMP75_ADDR 0x90

#define REG_TEMP 0x0
#define REG_CFG 0x1

#define CONFIG_DATA 0x60 //12bit resolution

static uint8_t tmp75present = 0;
static float tmp75temp = 0.f;

uint8_t TMP75_IsPresent()
{
	return tmp75present;
}

float TMP75_GetTemp()
{
	return tmp75temp;
}

static int32_t TMP75_Work()
{
	uint8_t buf[2];
	I2C_Xfer(TMP75_ADDR|1,buf,2,1);

	int tempSum = ((uint16_t)buf[0] << 8 | buf[1])>>4;
	tmp75temp = tempSum * 0.0625f;

	return TICKS_SECS(1);
}

void TMP75_Init()
{
	uint8_t buf[2] = { REG_CFG, CONFIG_DATA };
	int32_t ret = I2C_Xfer(TMP75_ADDR,buf,2,1);
	tmp75present = ret == 0;
	if (tmp75present)
	{
		buf[0] = REG_TEMP;
		I2C_Xfer(TMP75_ADDR,buf,1,1); //reset pointer to temperature register
	}
	printf("\nTMP75 sensor %s\n",tmp75present ? "found" : "not found");

	Sched_SetWorkfunc(TMP75_WORK,TMP75_Work);
	Sched_SetState(TMP75_WORK,tmp75present ? 2 : 0,0);
}
