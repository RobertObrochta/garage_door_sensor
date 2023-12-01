#include "sensors.h"
#include "stm32l4xx_hal.h"
#include <stdlib.h>

extern I2C_HandleTypeDef hi2c2;

void startToF(){

	 uint8_t addressWrite=0x52;
	 uint8_t turnOn[]={0x00,0x01};
	 HAL_I2C_Master_Transmit(&hi2c2,addressWrite,turnOn,2,1);
}

void getDistance(int *distance){
	 uint8_t addressWrite=0x52;
	  uint8_t addressRead=0x53;
	  uint8_t resultAddress[]={0x1e};
	  uint8_t rawData[]={0,0};

	  HAL_I2C_Master_Transmit(&hi2c2,addressWrite,resultAddress,1,1);

	  HAL_I2C_Master_Receive(&hi2c2,addressRead,rawData,2,1);
	  *distance=(rawData[0]<<8)+rawData[1]-20;

	  if(*distance<0){
		  *distance=0;
	  }
	  if(*distance>2000){
		  *distance=2000;
	  }
}
