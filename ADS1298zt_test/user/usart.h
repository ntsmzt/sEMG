#ifndef _usart_H
#define _usart_H

#include "stm32f10x.h"

#define STATE_HEAD 0xff01
#define STATE_LENGTH 0xff02
#define STATE_COMMAND 0xff03
#define STATE_ADDR 0xff04
#define STATE_VALUE 0xff05
#define STATE_CHECK 0xff06


void parse(u8 c);

void usart1_Init(int);	//USART1 ≥ı ºªØ
void usart1_send(char*, u8);
void usart1_sendByte(u8);


#endif

