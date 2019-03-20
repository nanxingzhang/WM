#include <msp430F5529.h>
#include <stdio.h>
#include "UCS_INIT.h"
#include "LCD12864.h"
#include "ADC12_INIT.h"
#include "ADS1118.h"
#include "DAC8571.h"
//#include<Turbidity.h>
//#include<UART.h>
//#include<testUART.h>
#include<PH-T.h>

#define CPU_F ((double)16000000)
#define delay_us(x) __delay_cycles((long)(CPU_F*(double)x/1000000.0))
#define Delay_Nms(x) __delay_cycles((long)(CPU_F*(double)x/1000.0))

#define SMCLK  1000000
#define FreqHz 200
#define Duty   60

#define Period SMCLK/FreqHz
#define Bright Period*Duty/100

#define DeadPeriod SMCLK/FreqHz/2
#define DeadBright DeadPeriod*Duty/100

unsigned int one_Percent = Period/100;
unsigned int ten_Percent = Period/10;
unsigned int max_Percent = Period;
unsigned int min_Percent = 0;

/*---------------------------------------------------------------------*/
float ADC_Value=0;

int main(void)
{
//	int a=1;
    WDTCTL = WDTPW | WDTHOLD;			//Stop watchdog timer
    UCS_init();
 	Lcd12864_Init();

 	Init_PH();
	while(1){
	    sendPHString("fejie");
	    lcd12864_disp_str(1,1,"ki");
		Delay_Nms(100);
	}

}

