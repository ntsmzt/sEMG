#ifndef ADS1298_H
#define ADS1298_H

#include "stm32f10x_spi.h"
#include "usart.h"

// ADS1298 commands
#define WREG 0x40
#define RREG 0x20
#define START 0x08
#define STOP 0x0a
#define RDATAC 0x10
#define SDATAC 0x11

#define ADS1298_DEVICE_ID 0x92

// Register Address
#define CONFIG1 0x01
#define CONFIG2 0x02
#define CONFIG3 0x03
#define CH1SET 0x05
#define CH2SET 0x06
#define CH3SET 0x07
#define CH4SET 0x08
#define CH5SET 0x09
#define CH6SET 0x0a
#define CH7SET 0x0b
#define CH8SET 0x0c
#define RLD_SENSP 0x0d
#define RLD_SENSN 0x0e

// GPIO Pin
#define CS_Pin GPIO_Pin_0
#define START_Pin GPIO_Pin_1
#define RESET_Pin GPIO_Pin_2
#define enableADS1298() GPIO_ResetBits(GPIOB,CS_Pin)
#define disableADS1298() GPIO_SetBits(GPIOB,CS_Pin)

void writeCommand(u8 cmd);
uint8_t EMG_SendByte(uint8_t TxData);
void ads1298_init(void);
u8 readRegister(u8 add);
void readNRegister(u8 start,u8 count, u8* regs);
int writeNRegister(u8 start, u8 count, u8* regs);
void beginReadDataC(void);
int writeRegister(u8 addr,u8 value);
int configForSquarewaveTest(void);
int configForNormalMeasurement(void);
int configForNoiseTest(void);

int resetADS1298(void);
u8 shakeHands(void);
void stopReadDataC(void);
void Read_CH(void);
int tryWriteRegister(u8 addr, u8 value, int tryTimes);
int configRLD(u8 rldp, u8 rldn);
/*

float readData(void);
void fakeHandler(void);






*/


#endif
