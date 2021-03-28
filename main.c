/**    THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS     **/
/** ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR OMMISSIONS **/
/*****************************************************************************
 *  Date   :        2005/04/5
 *  PROJECT:        LED
 *  Program:        Fujitsu
 *  CPU    :        FMC-16LX(MB90F387)
 *  Vcc,f  :        Vcc=5.0V,f=4MHz
 *  Sorce  :        ffmc16.c,start905s.asm
 *  Output :        P10~P15
/*****************************************************************************/
void initLCD();
void delay(int n);
void dataCtrl(unsigned char data);
void instCtrl4(unsigned char inst);
void readBF();
void instCtrl(unsigned char inst);
int determine(unsigned char* t1);

#include "_ffmc16.h"
#include "extern.h"
#include "monitor.h"

int dataCounter;
int attempt=0;
unsigned char data_[5];
unsigned char t1;
int flag=1;
int fflag=1;
int ffflag=0;
int counter=0;
int flag1=0;
unsigned char addCount;
void main(void)
{	
	
    __set_il(7);
	__EI();		/* enable interrupt(for Accemic) */
	IO_ADER.byte= 0x03;
	IO_DDR2.byte= 0xBF;
	IO_DDR5.byte= 0x0C;
	
	
	IO_ICR08.byte=0x00;
	IO_ENIR.bit.EN6=0;
	IO_ELVR.word=0x2000;
	IO_EIRR.bit.ER6=0;
	IO_ENIR.bit.EN6=1;
	
	
	IO_ICR02.byte=0x01;
	IO_TBTC.byte = 0x08;
	IO_TBTC.bit.TBIE=1;
	initLCD();
	while(1){
	//	initLCD();
		if(flag==1){
				dataCounter=0;
			while(attempt<3){
				instCtrl(0x83);
				dataCtrl('E');
				dataCtrl('N');
				dataCtrl('T');
				dataCtrl('E');
				dataCtrl('R');
				dataCtrl(' ');
				dataCtrl('P');
				dataCtrl('A');
				dataCtrl('S');
				dataCtrl('S');
				dataCtrl('C');
				dataCtrl('O');
				dataCtrl('D');
				dataCtrl('E');
				dataCtrl(':');
				instCtrl(0xC6);
				if(dataCounter==0)addCount=0xC6;
				if(flag1==1 && dataCounter<5){
					t1=IO_PDR5.byte;
					data_[dataCounter]=t1;
					if(t1==0x00){
						instCtrl(addCount);
						dataCtrl('1');
					//	delay(1000);
						addCount+=0x01;
					}
					else if(t1==0x10){
						instCtrl(addCount);
						dataCtrl('2');
					//	delay(1000);
						addCount+=0x01;
					}
					else if(t1==0x20){
						instCtrl(addCount);
						dataCtrl('3');
					//	delay(1000);
						addCount+=0x01;
					}
					else if(t1==0x40){
						instCtrl(addCount);
						dataCtrl('4');
					//	delay(1000);
						addCount+=0x01;
					}
					else if(t1==0x50){
						instCtrl(addCount);
						dataCtrl('5');
					//	delay(1000);
						addCount+=0x01;
					}
					else if(t1==0x60){
						instCtrl(addCount);
						dataCtrl('6');
					//	delay(1000);
						addCount+=0x01;
					}
					else if(t1==0x80){
						instCtrl(addCount);
						dataCtrl('7');
					//	delay(1000);
						addCount+=0x01;
					}
					else if(t1==0x90){
						instCtrl(addCount);
						dataCtrl('8');
					//	delay(1000);
						addCount+=0x01;
					}
					else if(t1==0xA0){
						instCtrl(addCount);
						dataCtrl('9');
					//	delay(1000);
						addCount+=0x01;
					}
					else if(t1==0xD0){
						instCtrl(addCount);
						dataCtrl('0');
					//	delay(1000);
						addCount+=0x01;
					}
					else if(t1==0xC0){
						instCtrl(addCount);
						dataCtrl('*');
					//	delay(1000);
						addCount+=0x01;
					}
					else if(t1==0xE0){
						instCtrl(addCount);
						dataCtrl('#');
					//	delay(1);
						addCount+=0x01;
					}
					else {
					instCtrl(addCount);
						dataCtrl('*');
					//	delay(1);
						addCount+=0x01;
					}
					//addCount+=0x01;
					dataCounter++;
					flag1=0;
					continue;
				}
				else if(flag1==0 && dataCounter<5) continue;
				else;
				if(determine(&data_[0])==1){
					ffflag=1;
					initLCD();
					instCtrl(0x83);
					dataCtrl('P');
					dataCtrl('A');
					dataCtrl('S');
					dataCtrl('S');
					dataCtrl('C');
					dataCtrl('O');
					dataCtrl('D');
					dataCtrl('E');
					dataCtrl(' ');
					dataCtrl('E');
					dataCtrl('N');
					dataCtrl('T');
					dataCtrl('E');
					dataCtrl('R');
					dataCtrl('E');
					dataCtrl('D');
					instCtrl(0xC4);
					dataCtrl('S');
					dataCtrl('U');
					dataCtrl('C');
					dataCtrl('C');
					dataCtrl('E');
					dataCtrl('S');
					dataCtrl('S');
					dataCtrl('F');
					dataCtrl('U');
					dataCtrl('L');
					dataCtrl('L');
					dataCtrl('Y');
					instCtrl(0x97);
					dataCtrl('P');
					dataCtrl('R');
					dataCtrl('E');
					dataCtrl('S');
					dataCtrl('S');
					dataCtrl(' ');
					dataCtrl('*');
					dataCtrl(' ');
					dataCtrl('T');
					dataCtrl('O');
					dataCtrl(' ');
					dataCtrl('L');
					dataCtrl('O');
					dataCtrl('C');
					dataCtrl('K');	
					while(fflag==1);
					initLCD();
				}
				else{
					attempt++;
					dataCounter=0;
					initLCD();
				} 
			}
			if(attempt>=3){
				flag=0;
				initLCD();
			}	
		}
		else{
			instCtrl(0x83);
			dataCtrl('S');
			dataCtrl('Y');
			dataCtrl('S');
			dataCtrl('T');
			dataCtrl('E');
			dataCtrl('M');
			dataCtrl(' ');
			dataCtrl('L');
			dataCtrl('O');
			dataCtrl('C');
			dataCtrl('K');
			dataCtrl('U');
			dataCtrl('P');
			instCtrl(0xC4);
			dataCtrl('M');
			dataCtrl('O');
			dataCtrl('D');
			dataCtrl('E');
		}
		
	}

}
int determine(unsigned char* t1){
	unsigned char dat [5];
	int i;
	dat[0]=0x00;
	dat[1]=0x10;
	dat[2]=0x20;
	dat[3]=0x40;
	dat[4]=0x50;
	for(i=0;i<5;i++){
		if((t1[i]!=dat[i]))return 0;
	}
	return 1;
}
void initLCD(){
	delay(1000);
	instCtrl4(0x03);
	delay(100);
	instCtrl4(0x03);
	delay(100);
	instCtrl4(0x03);
	delay(100);
	instCtrl4(0x02);
	delay(100);
	instCtrl(0x28);
	instCtrl(0x08);
	instCtrl(0x01);
	instCtrl(0x06);
	instCtrl(0x0E);
}

void delay(int n){
	counter=0;
	while(counter!=n);
	counter=0;
}

void dataCtrl(unsigned char data){
	IO_PDR2.byte=data>>4;
	IO_PDR2.bit.P24=1;
	IO_PDR5.bit.P52=1;
	IO_PDR5.bit.P53=0;
	delay(10);
	IO_PDR5.bit.P52=0;
	IO_PDR2.byte=data;
	IO_PDR2.bit.P24=1;
	IO_PDR5.bit.P52=1;
	IO_PDR5.bit.P53=0;
	delay(10);
	IO_PDR5.bit.P52= 0;
	readBF();
}

void instCtrl(unsigned char inst){
	IO_PDR2.byte = inst>>4;
	IO_PDR2.bit.P24= 0;
	IO_PDR5.bit.P52= 1;
	IO_PDR5.bit.P53= 0;
	delay(10);
	IO_PDR5.bit.P52= 0;
	IO_PDR2.byte=inst;
	IO_PDR2.bit.P24= 0;
	IO_PDR5.bit.P52= 1;
	IO_PDR5.bit.P53= 0;
	delay(10);
	IO_PDR5.bit.P52= 0;
	readBF();
}
void instCtrl4(unsigned char inst){
	IO_PDR2.byte = inst;
	IO_PDR2.bit.P24= 0;
	IO_PDR5.bit.P53= 0;
	IO_PDR5.bit.P52= 1;
	delay(30);
	IO_PDR5.bit.P52= 0;
	readBF();
}

void readBF(){
	/*unsigned char flag;
	IO_DDR2.byte= 0x00;
	IO_PDR5.bit.P50 = 0;
	IO_PDR5.bit.P51 = 1;
	IO_PDR5.bit.P52 = 1;
	
	do{
		flag = IO_PDR2.bit.P27;
	}while(flag);
	
	IO_PDR5.bit.P52=0;
	IO_DDR2.byte = 0xFF;*/
}

/*****************************************************************************
	interrupt routine
******************************************************************************/
/* reload timer interrupt routine */
__interrupt void timebase_int(void){
	IO_TBTC.bit.TBIE = 0;
	IO_TBTC.bit.TBOF = 0;
	counter++;
	IO_TBTC.bit.TBIE = 1; 
}
__interrupt void reload_int(void)
{
	
}

/* ADC interrupt routine */
__interrupt void ADC_int(void)
{
	
}

/* Ext interrupt routine */
__interrupt void ext_int(void)
{
	t1=IO_PDR5.byte;
	IO_EIRR.bit.ER6=0;
	
	if(ffflag==1){
		if(t1==0xC0){
			ffflag=0;
			dataCounter=0;
			attempt=0;
			fflag=0;
		}
	}
	else{
		if(flag1==0)flag1=1;
		else flag1=0;
	}
	
	IO_EIRR.bit.ER6=0;
	IO_ENIR.bit.EN6=1;
}


/* Vector Table */
#pragma section INTVECT,locate=0xfffc00
#pragma intvect _start		0x8  0x0	/* Reset Vector */
#pragma intvect reload_int	17			/* reload timer interrupt vecter */
#pragma intvect ADC_int		18			/* AD converter Vector */
#pragma intvect ext_int		27			/* Ext Interrupt vecter */
#pragma intvect timebase_int 16	
