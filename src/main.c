//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "SI_C8051F850_Register_Enums.h"
#include "SI_C8051F850_Defs.h"

//-----------------------------------------------------------------------------
// Defines
//-----------------------------------------------------------------------------

#define UART_SIZE_OUT   65
#define UART_SIZE_IN    8

#define FLOAT_OFFSET 1e3
#define FLOAT_SCALE 1e6

#define CORDIC_LUT_SIZE 20
#define CORDIC_GAIN 0.609

#define PI     3.1415
#define PI_2   1.5707

SBIT(LED0, SFR_P1, 0);  
SBIT(LED1, SFR_P1, 1);  
SBIT(TIME, SFR_P0, 0);  
SBIT(BUT0, SFR_P1, 7);  
SBIT(BUT1, SFR_P2, 1);  

//-----------------------------------------------------------------------------
// Prototypes
//-----------------------------------------------------------------------------

void setup(void);

void uartTx(U8 tx);
U8   uartRx(void);
U8   uartEmpty(void);

float cordic(U8 cos_n_sin, float theta);
float sin(float theta);
float cos(float theta);

void uartTxFloat(float tx);
float uartRxFloat(void);
//-----------------------------------------------------------------------------
// Look Up Tables
//-----------------------------------------------------------------------------

static const float cordic_lut[CORDIC_LUT_SIZE] ={
   0.785398163397, // = arctan(2^-0)	
   0.463647609001, // = arctan(2^-1)	
   0.244978663127, // = arctan(2^-2)	
   0.124354994547, // = arctan(2^-3)	
   0.062418809996, // = arctan(2^-4)	
   0.031239833430, // = arctan(2^-5)	
   0.015623728620, // = arctan(2^-6)	
   0.007812341060, // = arctan(2^-7)	
   0.003906230132, // = arctan(2^-8)	
   0.001953122516, // = arctan(2^-9)	
   0.000976562190, // = arctan(2^-10)	
   0.000488281211, // = arctan(2^-11)	
   0.000244140620, // = arctan(2^-12)	
   0.000122070312, // = arctan(2^-13)	
   0.000061035156, // = arctan(2^-14)	
   0.000030517578, // = arctan(2^-15)	
   0.000015258789, // = arctan(2^-16)
   0.000007639495, // = arctan(2^-17)
   0.000003814697, // = arctan(2^-18)
   0.000001907348  // = arctan(2^-19)	
};

//-----------------------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------------------
volatile U8 uart_out[UART_SIZE_OUT];
volatile U8 out_head;
volatile U8 out_tail;

volatile U8 uart_in[UART_SIZE_IN];
volatile U8 in_head;
volatile U8 in_tail;

//-----------------------------------------------------------------------------
// Main Routine
//-----------------------------------------------------------------------------

void main (void){    
   
   float i;
   setup();

   // Init UART
   out_head = 0;
   out_tail = 0;
   in_head = 0;
   in_tail = 0;
   
   // LEDs off
   LED0 = 1;  
   LED1 = 1;

   i = 0;
   while(1){   
      
      if(!uartEmpty()){
        
         uartTxFloat(sin(uartRxFloat()));
         
      }

   }
} 

//-----------------------------------------------------------------------------
// Interrupts
//-----------------------------------------------------------------------------

INTERRUPT (TIMER2_ISR, TIMER2_IRQn){        
   // UART RX
   if(SCON0_RI){ 
      SCON0_RI = 0;;
      uart_in[in_head] = SBUF0;
      in_head++;
      in_head %= UART_SIZE_IN;
   }
   
   // UART TX
   if(out_head != out_tail){
      SBUF0 = uart_out[out_tail]; 
      out_tail++;                 
      out_tail %= UART_SIZE_OUT;  
   }
   
   // Timer
   TMR2H = 253;     // Reset timer
   TMR2L = 240;     // Tuned for baud rate
   TMR2CN_TF2H = 0;  
}

//-----------------------------------------------------------------------------
// Sine/Cosine
//-----------------------------------------------------------------------------

float cordic(U8 cos_n_sin, float theta){
   float d,x,x_next,y,z,s,q; 
   U8 i;
   U8 is_neg;
   x = 1;
   y = 0;  
  
   is_neg = 0;
   z = theta; 
   // Pull in to -pi < z < pi
   while(PI < z){  
      z -= 2*PI;
   }
   while(z < -PI){
      z += 2*PI;
   }
   // Mirror
   if(PI_2 < z){
      z -= PI;
      is_neg = 1;
   }
   if(z < -PI_2){
      z += PI;
      is_neg = 1;
   } 
   d = 1;
   for(i=0;i<CORDIC_LUT_SIZE;i++){  
      if(z < 0){
         x_next = x + (d*y);
         y -= (d*x); 
         z += cordic_lut[i]; 
      } else {
         x_next = x - (d*y);
         y += (d*x); 
         z -= cordic_lut[i];
      }
      x = x_next;
      d /= 2; 
   }
   if(0 == cos_n_sin){
      y = y * CORDIC_GAIN;
      if(1 == is_neg){
         return -y;
      }else{
         return y;
      }
   }else{
      x = x * CORDIC_GAIN;
      if(1 == is_neg){
         return -x;
      }else{
         return x;
      }
   }
}

float sin(float theta){
   return cordic(0, theta);
}

float cos(float theta){
   return cordic(1, theta);
}

//-----------------------------------------------------------------------------
// UART
//-----------------------------------------------------------------------------

void uartTx(U8 tx){
   uart_out[out_head] = tx;
   out_head++;
   out_head %= UART_SIZE_OUT;
}


void uartTxFloat(float tx){
   // MSB first 
   union {
      float floating;
      U32 integer;
   } a;
   a.floating = tx; 
   uartTx((a.integer >> 24)  & 0xFF);
   uartTx((a.integer >> 16)  & 0xFF);
   uartTx((a.integer >> 8)   & 0xFF);
   uartTx(a.integer          & 0xFF);  
}

U8 uartRx(void){
   U8 rx = 0;
   if(!uartEmpty()){
      rx = uart_in[in_tail];
      in_tail++;
      in_tail %= UART_SIZE_IN;
   }
   return rx;
}

float uartRxFloat(void){
   // MSB first 
   union {
      float floating;
      U32 integer;
   } a; 
   while(uartEmpty());
   a.integer = uartRx();
   a.integer <<= 8;
   while(uartEmpty());
   a.integer|= uartRx();
   a.integer <<= 8;
   while(uartEmpty());
   a.integer |= uartRx();
   a.integer <<= 8;
   while(uartEmpty());
   a.integer |= uartRx(); 
   return a.floating;
}

U8 uartEmpty(void){
   if(in_tail == in_head){
      return 1;
   }else{
      return 0;
   }
}

//-----------------------------------------------------------------------------
// Setup micro
//-----------------------------------------------------------------------------

void setup(void){
   // Disabled watchdog
   WDTCN    = 0xDE;
   WDTCN    = 0xAD;
   // Clock
	CLKSEL   = CLKSEL_CLKSL__HFOSC 	      |     // Use 24.5MHz interal clock
			     CLKSEL_CLKDIV__SYSCLK_DIV_1;      // Do not divide     
   // Setup XBAR     
   P0MDOUT  = P0MDOUT_B4__PUSH_PULL|            // PWM
              P0MDOUT_B5__OPEN_DRAIN;
   //P0SKIP   = 0xCF;                             // Do not skip P0.4  
   P1MDOUT  = P1MDOUT_B0__PUSH_PULL|            // LED            
              P1MDOUT_B1__PUSH_PULL;            // LED
  // P1SKIP   = 0xFC;                             // Do not skip P1.0
                                                // Do not skip P1.1 
   XBR1     = XBR1_PCA0ME__CEX0;                // Route out PCA0.CEX0 on P0.2
   XBR0     = XBR0_URT0E__ENABLED;              // Route out UART P0.4 
   XBR2     = XBR2_WEAKPUD__PULL_UPS_ENABLED | 
              XBR2_XBARE__ENABLED;					 
   // Timer 0
	CKCON    = CKCON_T0M__PRESCALE|
              CKCON_SCA__SYSCLK_DIV_48;
	TMOD     = TMOD_T0M__MODE2;
	TCON     = TCON_TR0__RUN; 
   TH0      = 0x80;                             // Magic values from datasheet
	TL0      = 0x80;
   // Setup 230400 Baud UART 
   // BAUD gen on timer 1
	CKCON    |= CKCON_T1M__SYSCLK;
	TMOD     |= TMOD_T1M__MODE2;
	TCON     |= TCON_TR1__RUN; 
   TH1      = 0xCB;                             // Magic values from datasheet
	TL1      = 0xCB;
   // UART
	SCON0    |= SCON0_REN__RECEIVE_ENABLED;
   // Start 95.7KHz clock 
              PCA0CPM0_MAT__ENABLED   | 
              PCA0CPM0_PWM__ENABLED;
   PCA0CN   = PCA0CN_CR__RUN;   
   // Timer 2
	TMR2CN   = TMR2CN_TR2__RUN;
   // ADC
   ADC0MX   = ADC0MX_ADC0MX__ADC0P10; 
   ADC0CN0  = ADC0CN0_ADEN__ENABLED; 
   // Interrupt
	IE       = IE_EA__ENABLED | 
		        IE_ET0__ENABLED|
              IE_ET2__ENABLED; 
}






