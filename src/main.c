//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "SI_C8051F850_Register_Enums.h"
#include "SI_C8051F850_Defs.h"

//-----------------------------------------------------------------------------
// Defines
//-----------------------------------------------------------------------------

#define UART_SIZE_RX 32 
#define UART_SIZE_TX 32

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
// Typedefs
//-----------------------------------------------------------------------------

typedef union {
   float floating;
   U32   integer;
} flint_t; 

typedef struct {
   float re;
   float im;
} complex_t; 

//-----------------------------------------------------------------------------
// Prototypes
//-----------------------------------------------------------------------------

void setup(void);

void  cadd(complex_t * a, complex_t * b, complex_t * c);
void  cmul(complex_t * a, complex_t * b, complex_t * c);

float clog2(float n);

float cordic(U8 cos_n_sin, float theta);
float sin(float theta);
float cos(float theta);

void  uartInit(void);
void  uartTx(U8 tx);
U8    uartRx(void);
U8    uartRxPtr(void);
U8    uartRxWrap(void);
U8    uartRxWrapN(void);
U8    uartRxEmpty(void);
U8    uartRxFull(void);
U8    uartTxPtr(void);
U8    uartTxWrap(void);
U8    uartTxWrapN(void);
U8    uartTxEmpty(void);
U8    uartTxFull(void);
void  uartTxFloat(float tx);
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

__xdata volatile U8 uart_tx[UART_SIZE_TX];
volatile U8 tx_head;
volatile U8 tx_tail;
volatile U8 tx_head_wrap;
volatile U8 tx_tail_wrap;

__xdata volatile U8 uart_rx[UART_SIZE_RX];
volatile U8 rx_head;
volatile U8 rx_tail;
volatile U8 rx_head_wrap;
volatile U8 rx_tail_wrap;

//-----------------------------------------------------------------------------
// Main Routine
//-----------------------------------------------------------------------------

void main (void){    
    
   #ifdef COMPLEX_TEST
   __xdata complex_t a,b,c;
   #endif 

   uartInit();     
   setup();
  
   // LEDs off
   LED0 = 1;  
   LED1 = 1;

   while(1){   
      #ifdef BUFFER_TEST
      while(!uartRxFull());
      while(!uartRxEmpty()){
         uartTx(uartRx());  
      }
      while(!uartTxEmpty());
      uartInit();
      #endif
     
      #ifdef BANDWIDTH_TEST
      uartTx(uartRx());
      #endif
      
      #ifdef CORDIC_TEST
      uartTxFloat(sin(uartRxFloat()));
      #endif
      
      #ifdef CLOG2_TEST
      uartTxFloat(clog2(uartRxFloat()));
      #endif
      
      #ifdef COMPLEX_TEST
      a.re = uartRxFloat();
      a.im = uartRxFloat();
      b.re = uartRxFloat();
      b.im = uartRxFloat();
      
      cadd(&a,&b,&c);
      cmul(&a,&c,&b);
        
      // b = a * (a + b)  
      
      uartTxFloat(b.re);
      uartTxFloat(b.im);

      #endif

   }
} 

//-----------------------------------------------------------------------------
// Interrupts
//-----------------------------------------------------------------------------

INTERRUPT (TIMER2_ISR, TIMER2_IRQn){        
   // UART RX
   if(SCON0_RI){ 
      SCON0_RI = 0; 
      if(uartRxFull()){
         // Overflow
         LED1 = 0;
      }else{
         uart_rx[rx_head] = SBUF0;
         rx_head++;
         if(rx_head == UART_SIZE_RX){
            rx_head = 0;
            rx_head_wrap++;
            rx_head_wrap %= 2;
         }
      }
   }
   
   // UART TX
   if(!uartTxEmpty()){
      SBUF0 = uart_tx[tx_tail]; 
      tx_tail++;                 
      if(tx_tail == UART_SIZE_TX){
         tx_tail = 0; 
         tx_tail_wrap++;
         tx_tail_wrap %= 2;
      } 
   }
   
   // Timer
   TMR2H = 253;     // Reset timer
   TMR2L = 240;     // Tuned for baud rate
   TMR2CN_TF2H = 0;  
}

//-----------------------------------------------------------------------------
// Complex ops
//-----------------------------------------------------------------------------

void cadd(complex_t * a, complex_t * b, complex_t * c){
   c->re = a->re + b->re;
   c->im = a->im + b->im;
}

void cmul(complex_t * a, complex_t * b, complex_t * c){
   c->re = (a->re * b->re) - (a->im * b->im);
   c->im = (a->re * b->im) + (a->im * b->re);
}

//-----------------------------------------------------------------------------
// Logs
//-----------------------------------------------------------------------------

float clog2(float n){
   U32 i;
   U8 j;
   i = (U32)n;
   j = 0;
   while(i){
      i >>= 1;
      j++;
   }
   return (float)j;
}

//-----------------------------------------------------------------------------
// Sine/Cosine
//-----------------------------------------------------------------------------

float cordic(U8 cos_n_sin, float theta){
   __xdata float d,x,x_next,y,z; 
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

void uartInit(void){
   tx_head      = 0;
   tx_tail      = 0;
   tx_head_wrap = 0;
   tx_tail_wrap = 0;
   rx_head      = 0;
   rx_tail      = 0;
   rx_head_wrap = 0;
   rx_tail_wrap = 0;
}

void uartTx(U8 tx){
   while(uartTxFull());
   uart_tx[tx_head] = tx;
   tx_head++;
   if(tx_head == UART_SIZE_TX){
      tx_head = 0;
      tx_head_wrap++;
      tx_head_wrap %= 2;
   }
}

U8 uartRx(void){
   U8 rx;
   while(uartRxEmpty());
   rx = uart_rx[rx_tail];
   rx_tail++;
   if(rx_tail == UART_SIZE_RX){
      rx_tail = 0;
      rx_tail_wrap++;
      rx_tail_wrap %= 2;
   } 
   return rx;
}

void uartTxFloat(float tx){
   // MSB first 
   flint_t a;
   a.floating = tx; 
   uartTx((a.integer >> 24)  & 0xFF);
   uartTx((a.integer >> 16)  & 0xFF);
   uartTx((a.integer >> 8)   & 0xFF);
   uartTx(a.integer          & 0xFF);  
}

float uartRxFloat(void){
   // MSB first  
   flint_t a;
   a.integer = uartRx();
   a.integer <<= 8;
   a.integer|= uartRx();
   a.integer <<= 8;
   a.integer |= uartRx();
   a.integer <<= 8;
   a.integer |= uartRx(); 
   return a.floating;
}

U8 uartRxPtr(void){
   if(rx_tail == rx_head){
      return 1;
   }else{
      return 0;
   }
}

U8 uartRxWrap(void){
   if(rx_tail_wrap == rx_head_wrap){
      return 1;
   }else{
      return 0;
   }
}

U8 uartRxWrapN(void){
   if(rx_tail_wrap != rx_head_wrap){
      return 1;
   }else{
      return 0;
   }
}

U8 uartRxEmpty(void){   
   return uartRxPtr() * uartRxWrap();
}

U8 uartRxFull(void){
   return uartRxPtr() * uartRxWrapN(); 
}

U8 uartTxPtr(void){
   if(tx_tail == tx_head){
      return 1;
   }else{
      return 0;
   }
}

U8 uartTxWrap(void){
   if(tx_tail_wrap == tx_head_wrap){
      return 1;
   }else{
      return 0;
   }
}

U8 uartTxWrapN(void){
   if(tx_tail_wrap != tx_head_wrap){
      return 1;
   }else{
      return 0;
   }
}

U8 uartTxEmpty(void){   
   return uartTxPtr() * uartTxWrap();
}

U8 uartTxFull(void){
   return uartTxPtr() * uartTxWrapN(); 
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
   P1MDOUT  = P1MDOUT_B0__PUSH_PULL|            // LED            
              P1MDOUT_B1__PUSH_PULL;            // LED 
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






