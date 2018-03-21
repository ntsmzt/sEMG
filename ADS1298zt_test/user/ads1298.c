#include "ads1298.h"
#include "schedule.h"
#include "stm32f10x_exti.h"

void ads1298_init(void)      //ads1298初始化//IO口初始化
{
    GPIO_InitTypeDef GPIO_InitStructure;
    SPI_InitTypeDef  SPI_InitStructure;

    RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB, ENABLE );//PORTA、PORTB时钟使能 
    RCC_APB2PeriphClockCmd(	RCC_APB2Periph_SPI1,  ENABLE );//SPI1时钟使能 
    
    //EMG_Ready   DRDY  初始化   端口PA.4   
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//上拉输入
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
    GPIO_Init(GPIOA,&GPIO_InitStructure);
    
    //EMG_SPI_CLK  MISO  MOSI  初始化  PA5/6/7
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽输出
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA,SCK
    
		GPIO_SetBits(GPIOA,GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);  //PA5/6/7上拉
		
		//配置SPI1的输出
    SPI_I2S_DeInit(SPI1); //将SPI1寄存器重设为缺省值
    SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;  //设置SPI单向或者双向的数据模式:SPI设置为双线双向全双工
    SPI_InitStructure.SPI_Mode = SPI_Mode_Master;		//设置SPI工作模式:设置为主SPI
    SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;		//设置SPI的数据大小:SPI发送接收8位帧结构
    SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;		//串行同步时钟的空闲状态为高电平
    SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;	//串行同步时钟的第二个跳变沿（上升或下降）数据被采样
    SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;		//NSS信号由硬件（NSS管脚）还是软件（使用SSI位）管理:内部NSS信号有SSI位控制
    SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;		//定义波特率预分频的值:波特率预分频值为256
    SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;	//指定数据传输从MSB位还是LSB位开始:数据传输从MSB位开始
    SPI_InitStructure.SPI_CRCPolynomial = 7;	//CRC值计算的多项式
    SPI_Init(SPI1, &SPI_InitStructure);  //根据SPI_InitStruct中指定的参数初始化外设SPIx寄存器
    
    SPI_NSSInternalSoftwareConfig(SPI1,SPI_NSSInternalSoft_Set);//为选定的SPI软件配置内部NSS管脚
    SPI_Cmd(SPI1, ENABLE); //使能SPI外设
    
    //EMG_Reset/CS/START 
    GPIO_InitStructure.GPIO_Mode= GPIO_Mode_Out_PP;//端口模式：推挽输出
    GPIO_InitStructure.GPIO_Pin = RESET_Pin | CS_Pin | START_Pin;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB,&GPIO_InitStructure);
    
		
		
   //GPIO_SetBits(GPIOB,RESET_Pin); //Reset置高点平
   GPIO_ResetBits(GPIOB,START_Pin);//Start置低电平
	
		delayMs(500);
}


int resetADS1298(void)                  //对ads1298进行配置
{
    int trytime ,r;
		u8 addr; 
    GPIO_SetBits(GPIOB,RESET_Pin);             //Reset = 1
    GPIO_ResetBits(GPIOB,CS_Pin|START_Pin);    //CS, START = 0
    delayMs(10);
	
    for (trytime=0;trytime<5;trytime++)                     
    {      
        GPIO_ResetBits(GPIOB,RESET_Pin);                   //Reset = 0
        delayMs(500);
        GPIO_SetBits(GPIOB,RESET_Pin);                     //Reset = 1
        delayMs(10);
        
        writeCommand(SDATAC);
        if (shakeHands()==ADS1298_DEVICE_ID)
            break;
        delayMs(10);
    }
    if (trytime==5)
        return -1;
    
		r = tryWriteRegister(CONFIG3,0xc0,5);   //  0xdc enable REFBUF, RLD_BUF
    if (r!=0)
        return -1;
	
		delayMs(100);
		
		r = tryWriteRegister(CONFIG1,0x86,5);   // HR Mode: 500 SPS 
    if (r!=0)
        return -1;
		
		r = tryWriteRegister(CONFIG2,0x00,5);   // HR Mode: 500 SPS 
    if (r!=0)
        return -1;
		
		for(addr=CH1SET;addr<=CH8SET;addr++) // CH 1~8
  {
		while(r!=0)
		{
		r = tryWriteRegister(addr,0x01,5);   // Ch to Test signal
		}
		r=-1;
	}    
		/*
		r = tryWriteRegister(RLD_SENSP,0xff,5);   // RLD Positive 
    if (r!=0)
        return -1;
		
		r = tryWriteRegister(RLD_SENSN,0xff,5);   // RLD Negative
    if (r!=0)
        return -1;
    */
		return 0;
}

/*
int configForSquarewaveTest()       //配置成方波测量模式
{ 
	int r;
	u8 addr;
	r = tryWriteRegister(CONFIG2,0x10,5);   // signal internal
  if (r!=0)
      return -1;
	
  for(addr=CH1SET;addr<=CH8SET;addr++) // CH 1~8
  {
		r = tryWriteRegister(addr,0x05,5);   // Ch to Test signal
		if (r!=0)
      return -1;
  }    
	return 0;
}
*/

int configForSquarewaveTest()       //配置成方波测量模式
{ 
	int r=-1,n=1;
	u8 addr;
	
	while(r!=0)
	r = tryWriteRegister(CONFIG2,0x10,5);   // signal internal
	r=-1;
  
	for(addr=CH1SET;addr<=CH8SET;addr++) // CH 1~8
  {
		while(r!=0)
		{
		r = tryWriteRegister(addr,0x05,5);   // Ch to Test signal
		}
		r=-1;
	}    
	return 0;
}

void Read_CH()
{	
	u8 addr;
	int i,j;
for(addr=CH1SET;addr<=CH8SET;addr++) // CH 1~8
  {
		usart1_sendByte(addr);
		j=readRegister(addr);	
		usart1_sendByte(j);
  } 

}	

int configForNoiseTest(void)            //配置成噪声测量模式
{
	int r;
	u8 addr;
	r = tryWriteRegister(CONFIG2,0x00,5);   // signal external
  if (r!=0)
      return -1;
	
	for(addr=CH1SET;addr<=CH8SET;addr++) // CH 1~8
  {
		r = tryWriteRegister(addr,0x01,5);   // Ch to shorted
		if (r!=0)
      return -1;
  }    
	return 0;
}

int configForNormalMeasurement(void)    //配置成正常测量模式
{
	int r;
	u8 addr;
	r = tryWriteRegister(CONFIG2,0x00,5);   // signal external
  if (r!=0)
      return -1;
	
  for(addr=CH1SET;addr<=CH8SET;addr++) // CH 1~8
  {
		r = tryWriteRegister(addr,0x00,5);   // 
		if (r!=0)
      return -1;
  }    
	return 0; 
}

void beginReadDataC()               //设置中断              
	{
	  EXTI_InitTypeDef EXTI_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
		
		/* Enable SYSCFG clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);    //开启AFIO时钟
 
    //EXTI4 NVIC 配置
    NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;       		//使能外部中断通道
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=4 ;	//抢占优先级3
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;				//子优先级3
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;						//IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);														//根据指定的参数初始化VIC寄存器
    
    /* Connect EXTI4 Line to PA4 pin */
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource4);
    EXTI_InitStructure.EXTI_Line = EXTI_Line4;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //下降沿中断
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);   //初始化中断线函数
	
	
		writeCommand(RDATAC);
		writeCommand(START);
		delayMs(5);
		// START HIGH
    GPIO_SetBits(GPIOB,GPIO_Pin_2);
    delayMs(10);
    enableADS1298();
} 
	

void EXTI4_IRQHandler(void)             //中断服务函数
{       
    int i;
    uint8_t tmp,sum;
   
    sum=0;
    usart1_sendByte(0xff);   		 	//包头两个0xff 
    usart1_sendByte(0xff);
    usart1_sendByte(0x01);    		//EMG数据命令0x01
		
    for (i=0;i<27;i++)            //发送EMG数据，共27个字节
    {
        tmp = EMG_SendByte(0xff);
        usart1_sendByte(tmp);
        sum += tmp;
    }
    usart1_sendByte(sum);//send checksum

		EXTI_ClearITPendingBit(EXTI_Line4);
}

u8 shakeHands(void)                     //握手
{
    u8 deviceID;
    deviceID=readRegister(0x00);
    return deviceID;
}

void stopReadDataC(void)                
{
	GPIO_ResetBits(GPIOB,CS_Pin|START_Pin);    //CS, START = 0
	
	writeCommand(STOP);
  delayMs(5);
	
	writeCommand(SDATAC);  
	delayMs(5);
}


int configRLD(u8 rldp, u8 rldn)         //设置RLD寄存器，定义configRLD函数，函数值为整型，形式参数rldp，rldn为无符号字符型
{
		int r;
		r = tryWriteRegister(RLD_SENSP,rldp,5);   // RLD Positive 
    if (r!=0)
        return -1;
		
		r = tryWriteRegister(RLD_SENSN,rldn,5);   // RLD Negative
    if (r!=0)
        return -1;
    return 0;
}

//-------------------------------- 底层函数----------------------------------------


uint8_t EMG_SendByte(uint8_t TxData)    //发送\接收数据
{
    while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET);  //检查发送是否完成，完成以后再发送数据
    SPI_I2S_SendData(SPI1,TxData); //通过外设SPIx发送一个数据
    while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET);  //检查接收受标志位，是否可以接受 
	  return SPI_I2S_ReceiveData(SPI1);   //返回通过SPIx最近接收的数据	
}

u8 readRegister(u8 addr)    //读寄存器，函数值为无符号字符型，形式参数start为字符型，count为无符号字符型
{
    char r;
    enableADS1298();
    EMG_SendByte(RREG|addr);
    EMG_SendByte(0x00); //读取1个
    r=EMG_SendByte(0xff); 
    disableADS1298();
    return r;
}

int writeRegister(u8 addr,u8 value)     //写寄存器         
{
    enableADS1298();
    EMG_SendByte(WREG|addr);
    EMG_SendByte(0x00); //写1个
    EMG_SendByte(value);
    disableADS1298();
    delayMs(1);
    if (readRegister(addr)==value)
        return 0;
    else
        return -1;
}

void readNRegister(u8 start,u8 count, u8* regs)
{
	u8 i;
	enableADS1298();
	EMG_SendByte(RREG|start);
	EMG_SendByte(count-1);
	for(i=0;i<count;i++)
		regs[i] = EMG_SendByte(0x00);
	disableADS1298();
}

int writeNRegister(u8 start, u8 count, u8* regs)
{
	u8 i;
	u8 val;
	enableADS1298();
	EMG_SendByte(WREG|start);
	EMG_SendByte(count-1);
	for(i=0;i<count;i++)
		EMG_SendByte(regs[i]);
	
	//check
	EMG_SendByte(RREG|start);
	EMG_SendByte(count-1);
	for(i=0;i<count;i++)
	{
		val = EMG_SendByte(0x00);
		if(val!=regs[i])
			break;
	}
	disableADS1298();
	
	if(i<count)
		return -1;
	else
		return 0;
}

void writeCommand(u8 cmd)
{
		enableADS1298();
    EMG_SendByte(cmd);
    EMG_SendByte(0x00); //等待至少4个周期
    disableADS1298();
}

//----------------------------------------------
// 功能: 写寄存器，最多尝试 tryTimes 次
// 返回：0  - 成功
//       -1 - 失败
int tryWriteRegister(u8 addr, u8 value, int tryTimes)
{
	int i,r;
	for(i=0;i<tryTimes;i++)
	{
		r = writeRegister(addr,value);
		if(r==0)
			break;
		delayMs(10);
	}
	if(i==tryTimes)
		return -1;
	else
		return 0;
}

