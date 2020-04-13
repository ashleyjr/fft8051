//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "SI_C8051F850_Register_Enums.h"
#include "SI_C8051F850_Defs.h"
#include "fft8051.h"

//-----------------------------------------------------------------------------
// Defines
//-----------------------------------------------------------------------------

#define UART_SIZE_RX 38
#define UART_SIZE_TX 2 

SBIT(LED0, SFR_P1, 0);  
SBIT(LED1, SFR_P1, 1);  
SBIT(TIME, SFR_P0, 0);  
SBIT(BUT0, SFR_P1, 7);  
SBIT(BUT1, SFR_P2, 1);  

//-----------------------------------------------------------------------------
// Prototypes
//-----------------------------------------------------------------------------

void  setup(void);

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

//-----------------------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------------------

volatile U8 uart_tx[UART_SIZE_TX];
volatile U8 tx_head;
volatile U8 tx_tail;
volatile U8 tx_head_wrap;
volatile U8 tx_tail_wrap;

volatile U8 uart_rx[UART_SIZE_RX];
volatile U8 rx_head;
volatile U8 rx_tail;
volatile U8 rx_head_wrap;
volatile U8 rx_tail_wrap;

volatile static __xdata complex_t s[N]; 
volatile static unsigned char s_ptr;

//-----------------------------------------------------------------------------
// Main Routine
//-----------------------------------------------------------------------------

void main (void){    
   static unsigned char i;  

   s_ptr = 0; 
   LED0 = 0;  
   LED1 = 0;

   uartInit();     
   setup();
 
   while(1){    
      #ifdef COMPARE
      for(i=0;i<N;i++){
         s[i].re = uartRx() - 128;
         s[i].im = 0;
      }
      fft(s);
      for(i=0;i<N;i++){
         uartTx(mag(&s[i]));        
      } 
      #endif


      #ifndef COMPARE
      while(s_ptr != N); 
      // Sync byte    
      uartTx((unsigned char)255);
      // FFT it
      LED0 = 1;
      fft(s); 
      LED0 = 0;
      for(i=0;i<N_2;i++){
         uartTx(mag(&s[i]));        
      }                          
      // Start new sample
      s_ptr = 0; 
      #endif
   }
} 

//-----------------------------------------------------------------------------
// Interrupts
//-----------------------------------------------------------------------------

INTERRUPT (TIMER1_ISR, TIMER1_IRQn){   
   #ifdef COMPARE
   // UART RX
   if(SCON0_RI){ 
      SCON0_RI = 0; 
      if(!uartRxFull()){ 
         uart_rx[rx_head] = SBUF0;
         rx_head++;
         if(rx_head == UART_SIZE_RX){
            rx_head = 0;
            rx_head_wrap++;
            rx_head_wrap %= 2;
         }
      }
   }
   #endif
}
INTERRUPT (TIMER2_ISR, TIMER2_IRQn){           
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
   TMR2CN &= ~TMR2CN_TF2H__SET;
}

INTERRUPT (TIMER3_ISR, TIMER3_IRQn){          
 
   LED1 = (LED1) ? 0 : 1;

   // ADC Sample
   if(s_ptr < N){ 
      ADC0CN0 |= ADC0CN0_ADBUSY__SET;
      while(ADC0CN0 & ADC0CN0_ADBUSY__SET);
      
      // Places bias at 1V
      s[s_ptr].re = (ADC0 >> 1) - 155;
      s_ptr++;
   } 
   
   TMR3CN &= ~TMR3CN_TF3H__SET;
   
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
   P0MDOUT  = P0MDOUT_B4__PUSH_PULL;
   P1SKIP   = P1SKIP_B0__SKIPPED|
              P1SKIP_B1__SKIPPED;
   P1MDOUT  = P1MDOUT_B0__PUSH_PULL|            // LED            
              P1MDOUT_B1__PUSH_PULL;            // LED 
   XBR0     = XBR0_URT0E__ENABLED;              // Route out UART P0.4 
   XBR2     = XBR2_WEAKPUD__PULL_UPS_DISABLED | 
              XBR2_XBARE__ENABLED;					  
   // Timer control
	CKCON    = CKCON_T0M__PRESCALE|
              CKCON_SCA__SYSCLK_DIV_12;  
   // Setup 115200 Baud UART 
   // BAUD gen on timer 1
	CKCON    |= CKCON_T1M__SYSCLK;
	TMOD     |= TMOD_T1M__MODE2;
	TCON     |= TCON_TR1__RUN; 
   TH1      = 0x96;                             // Magic values from datasheet
	TL1      = 0x96;
   // UART
	SCON0    |= SCON0_REN__RECEIVE_ENABLED; 
   // Timer 2
	TMR2CN   = TMR2CN_TR2__RUN;  
   TMR2L    = 0xB0;
   TMR2H    = 0xFF;
   TMR2RLL  = 0xB0;
   TMR2RLH  = 0xFF;
   // Timer 3
	TMR3CN   = TMR3CN_TR3__RUN;   // ~44 KHz
   TMR3L    = 0xD0;
   TMR3H    = 0xFF;
   TMR3RLL  = 0xD0;
   TMR3RLH  = 0xFF;
   // ADC
   ADC0MX   = ADC0MX_ADC0MX__ADC0P3;
   ADC0CF   = ADC0CF_ADGN__GAIN_1 |       // ADC gain set to 1
              ADC0CF_ADTM__TRACK_NORMAL;  // Immediate covert
   REF0CN   = REF0CN_REFSL__VDD_PIN;      // Ref to VDD
   ADC0CN0 &= ~ADC0CN0_ADCM__FMASK;
   ADC0CN0 |= ADC0CN0_ADEN__ENABLED |
              ADC0CN0_ADCM__ADBUSY; 
   // Interrupts
	IE   = IE_EA__ENABLED | 
		    IE_ET0__ENABLED|
          IE_ET1__ENABLED|
          IE_ET2__ENABLED;
   EIE1 = EIE1_ET3__ENABLED;
   IP   = IP_PT2__HIGH;    
}






