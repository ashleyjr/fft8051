//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "SI_C8051F850_Register_Enums.h"
#include "SI_C8051F850_Defs.h"
#include "fft8051.h"

//-----------------------------------------------------------------------------
// Defines
//-----------------------------------------------------------------------------

#define UART_SIZE_RX 4 
#define UART_SIZE_TX 4 

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

//-----------------------------------------------------------------------------
// Main Routine
//-----------------------------------------------------------------------------

void main (void){    
    
   static __xdata complex_t s[N]; 
   static unsigned int i;
   static unsigned long t;
   uartInit();     
   setup();
  
   // LEDs off
   LED0 = 1;  
   LED1 = 1;

   while(1){    
      for(i=0;i<N;i++){
         s[i].re = uartRx() - 128;
         s[i].im = 0;
      }
      fft(s);
      for(i=0;i<N;i++){
         t = mag(&s[i]);
         uartTx((char)(t & 0xFF));
         uartTx((char)((t >> 8) & 0xFF));
      }
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






