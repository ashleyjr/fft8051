//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include "SI_C8051F850_Register_Enums.h"
#include "SI_C8051F850_Defs.h"
//#include "fft8051.h"

//-----------------------------------------------------------------------------
// Defines
//-----------------------------------------------------------------------------

#define UART_SIZE_RX 20
#define UART_SIZE_TX 5

#define DISP_SRC_0      0x70
#define DISP_SRC_1      0x74
#define DISP_SINK_0     0x7E
#define DISP_SINK_1     0x7A
#define DISP_SINK_2     0x76
#define DISP_SINK_3     0x72

#define  WRITE                    0x00 // SMBus WRITE command
#define  READ                     0x01 // SMBus READ command

// Device addresses (7 bits, LSB is a don't care)
#define  SLAVE_ADDR               0xF0 // Device address for slave target

// Status vector - top 4 bits only
#define  SMB_MTSTA                0xE0 // (MT) start transmitted
#define  SMB_MTDB                 0xC0 // (MT) data byte transmitted
#define  SMB_MRDB                 0x80 // (MR) data byte received


SBIT(SHDN, SFR_P1, 0);  
SBIT(LED,  SFR_P1, 1);  
SBIT(TIME, SFR_P0, 0);  
SBIT(BUT0, SFR_P1, 7);  
SBIT(BUT1, SFR_P2, 1);  


static const U8 sink_lut[4] = {
   DISP_SINK_0,
   DISP_SINK_1,
   DISP_SINK_2,
   DISP_SINK_3,
};

static const U16 cols[32] = {
   0b1010101010101010, 
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010,
   0b1010101010101010
};

//-----------------------------------------------------------------------------
// Prototypes
//-----------------------------------------------------------------------------

void  setup(void);

void  driver(void);
void  disp (U16 src, U32 sink);

void  smbWrite(U8 addr, U8 data);

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

//volatile static __xdata complex_t s[N]; 
//volatile static unsigned char s_ptr;

volatile U8 smb_data_out;                       // Global holder for SMBus data.
volatile U8 smb_target;                             // Target SMBus slave address
volatile U8 smb_busy;                 // Software flag to indicate when the
volatile U8 SMB_RW;                   // Software flag to indicate the

volatile U8 disp_on;
volatile U8 colu;
volatile U8 coll;
volatile U8 state;

//-----------------------------------------------------------------------------
// Main Routine
//-----------------------------------------------------------------------------

void main (void){    
   static unsigned char i,j;
  
   //s_ptr = 0; 
   SHDN = 1;  
   LED  = 1;
   
   // Driver state machine
   disp_on = 0;
   colu = 16;
   coll = 0;
   state = 0;

   uartInit();     
   setup();
 
   i = 0;

   for(i=0;i<50;i++){
      for(j=0;j<255;j++){
         uartTx(i);
      }
   }
   SHDN = 0;
   LED = 0;
 
   for(i=0;i<50;i++){
      for(j=0;j<255;j++){
         uartTx(i);
      }
   } 

   LED = 1;
   disp_on = 1;
   while(1){    
    
      //smbWrite(DISP_SINK_0,    0x00);           
      //smbWrite(DISP_SRC_0,     (0xFF7F >> row));
      //driver(); 
      //for(k=0;k<1000;k++){
      //   uartTx(k);
      //}
      //for(i=0;i<8;i++){
      //   for(j=0;j<8;j++){
      //      disp((0x8000 >> i),~(0x80000000 >> j));
      //      for(k=0;k<100;k++){
      //         uartTx(k);
      //      }
      //   }
   
      //   for(j=0;j<8;j++){
      //      disp((0x0080 >> i),~(0x80000000 >> j));
      //      for(k=0;k<100;k++){
      //         uartTx(k);
      //      }
      //   }
      //} 
      //disp(0x8000,~0x80000000);
      //for(k=0;k<500;k++){uartTx(k);}                                         
   
      //disp(0x8000,~0x40000000);
      //for(k=0;k<500;k++){uartTx(k);}                                         
   
      //disp(0x4000,~0x80000000);
      //for(k=0;k<500;k++){uartTx(k);}                                         
   
      //disp(0x4000,~0x40000000);
      //for(k=0;k<500;k++){uartTx(k);}                                         
   
   }
      
      
      //#ifdef COMPARE
      //for(i=0;i<N;i++){
      //   s[i].re = uartRx() - 128;
      //   s[i].im = 0;
      //}
      //fft(s);
      //for(i=0;i<N;i++){
      //   uartTx(mag(&s[i]));        
      //} 
      //#endif


      //#ifndef COMPARE
      //while(s_ptr != N); 
      //// Sync byte    
      //uartTx((unsigned char)255);
      //// FFT it
      //LED0 = 1;
      //fft(s); 
      //LED0 = 0;
      //for(i=0;i<N_2;i++){
      //   uartTx(mag(&s[i]));        
      //}                          
      //// Start new sample
      //s_ptr = 0; 
      //#endif
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
   U8 sinku;
   U8 sinkl;

   EIE1 &= ~EIE1_ET3__ENABLED;

   LED = (LED) ? 0 : 1;

   if(disp_on){

      // Divide by 8
      sinku = colu >> 3;
      sinku = sink_lut[sinku];
      sinkl = coll >> 3;
      sinkl = sink_lut[sinkl];

      switch(state){ 
     
         // Turn everything off
         case 0:  smbWrite(DISP_SRC_0,    0xFF); 
                  state = 1;
                  break;
         case 1:  smbWrite(DISP_SRC_1,    0xFF);
                  state = 2;
                  break;
         case 2:  smbWrite(DISP_SINK_0,   0xFF);
                  state = 3;
                  break;
         case 3:  smbWrite(DISP_SINK_1,   0xFF);
                  state = 4;
                  break;
         case 4:  smbWrite(DISP_SINK_2,   0xFF);
                  state = 5;
                  break;
         case 5:  smbWrite(DISP_SINK_3,   0xFF);
                  state = 6;
                  break;      
                     
         
         case 6:  smbWrite(sinku,  (cols[colu] >> 8)); 
                  state = 7; 
                  break;
         case 7:  smbWrite(sinkl,  (cols[coll])); 
                  state = 8; 
                  break;
         case 8:  smbWrite(DISP_SRC_1,    (0xFF7F >> (colu % 8)));
                  state = 9;
                  break;
         case 9:  smbWrite(DISP_SRC_0,    (0xFF7F >> (coll % 8)));
                  state = 10;
                  break;
         case 10: smbWrite(sinku,  0xFF);
                  colu++;
                  colu %= 32;
                  state = 11;
                  break;
         case 11: smbWrite(sinkl,  0xFF);
                  state = 6;
                  coll++;
                  coll %= 32;
                  break; 
      }
      
   }

   // ADC Sample
   //if(s_ptr < N){ 
   //   ADC0CN0 |= ADC0CN0_ADBUSY__SET;
   //   while(ADC0CN0 & ADC0CN0_ADBUSY__SET);
   //   
   //   // Places bias at 1V
   //   s[s_ptr].re = (ADC0 >> 1) - 155;
   //   s_ptr++;
   //} 
   
   TMR3CN &= ~TMR3CN_TF3H__SET;
   EIE1 |= EIE1_ET3__ENABLED;

}

INTERRUPT(SMBUS0_ISR, SMBUS0_IRQn){ 
   static U8 ADDR_SEND = 0;   // Used by the ISR to flag byte transmissions as slave addresses
   //if(SMB0CN_ARBLOST == 0){ 
      switch (SMB0CN & 0xF0) {
         // Master Transmitter/Receiver: START condition transmitted.
         case SMB_MTSTA:   SMB0DAT = smb_target;            // Load address of the target slave 
                           SMB0CN_STA = 0;                  // Manually clear START bit
                           ADDR_SEND = 1;
                           break;
         // Master Transmitter: Data byte transmitted only writes
         case SMB_MTDB:    if(SMB0CN_ACK) {
                              if (ADDR_SEND) {              // address,
                                 ADDR_SEND = 0;             // Next byte is not a slave address
                                 SMB0DAT = smb_data_out;
                              }else{                        // address,
                                 SMB0CN_STO = 1;            // Set SMB0CN_STO to terminate transfer
                                 smb_busy = 0;              // And free SMBus interface
                              }
                           
                           } else {
                              SMB0CN_STO = 1;               // Send STOP condition,followed
                              SMB0CN_STA = 1;               // By a START 
                           }
                           break;
         default:          break;

      } 
   //}
   SMB0CN_SI = 0; //Clear interrupt flag 
}

//-----------------------------------------------------------------------------
// Display 
//-----------------------------------------------------------------------------

U8 rev(U8 b){
   b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
   b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
   b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
   return b;
}



// Display
// .  .  .  ... . . . 15 
// .  .  .  ... . . . 14
// .  .  .  ... . . . 13 
// .  .  .  ... . . . .
// .  .  .  ... . . . 2 
// .  .  .  ... . . . 1 
// .  .  .  ... . . . 0 
// 31 30 29 ... 2 1 0  

void disp (U16 src, U32 sink){ 
   U8 src_0, src_1;
   U8 sink_0, sink_1, sink_2, sink_3;

   // Reorder bits to map to LEDs 
   src_1 = src; 
   src_1 = ~src_1;

   src_0 = src >> 8; 
   src_0 = ~src_0;

   sink_3 = sink;
   sink_2 = sink >> 8;
   sink_1 = sink >> 16;
   sink_0 = sink >> 24;
   
   smbWrite(DISP_SRC_0,    src_0);
   smbWrite(DISP_SRC_1,    src_1);
   smbWrite(DISP_SINK_0,   sink_0);
   smbWrite(DISP_SINK_1,   sink_1);
   smbWrite(DISP_SINK_2,   sink_2);
   smbWrite(DISP_SINK_3,   sink_3);
}

void driver(void){
   U16 k;
   U8  i;
   // Everything off
   smbWrite(DISP_SINK_0,    0x00);
   smbWrite(DISP_SINK_1,    0x00);
   smbWrite(DISP_SINK_2,    0x00);
   smbWrite(DISP_SINK_3,    0x00);
   
   // Sweep bottom bank
   for(i=0;i<8;i++){
      smbWrite(DISP_SRC_0, (0xFFFF << i));
      for(k=0;k<100;k++){
         uartTx(k);
      }
      smbWrite(DISP_SRC_0, (0xFFFE << i));
   }

   // Sweep top bank
   for(i=0;i<8;i++){
      smbWrite(DISP_SRC_1, (0xFEFF << i));    
      for(k=0;k<100;k++){
         uartTx(k);
      }  
   
   }


}

//-----------------------------------------------------------------------------
// SMB 
//-----------------------------------------------------------------------------

void smbWrite (U8 addr, U8 data){
   while(smb_busy);
   smb_data_out = data;
   smb_target = addr; 
   smb_busy = 1;                       // Claim SMBus (set to busy)  
   SMB0CN_STA = 1;                     // Start transfer 
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
   XBR0     = XBR0_SMB0E__ENABLED| 
              XBR0_URT0E__ENABLED;              // Route out UART P0.4 
   XBR2     = XBR2_WEAKPUD__PULL_UPS_DISABLED | 
              XBR2_XBARE__ENABLED;					  
   // Timer control
	CKCON    = CKCON_T0M__PRESCALE|
              CKCON_SCA__SYSCLK_DIV_12;  
   // SMBus
   SMB0CF   = SMB0CF_INH__SLAVE_DISABLED|
              SMB0CF_SMBCS__TIMER0|
              SMB0CF_SMBFTE__FREE_TO_ENABLED| 
              SMB0CF_ENSMB__ENABLED; 
   // I2C clock on timer 0
   // BAUD gen 115200 on timer 1
	CKCON    |= CKCON_T1M__SYSCLK;
	TMOD     |= TMOD_T0M__MODE2 |
               TMOD_T1M__MODE2;
	TCON     |= TCON_TR0__RUN |
               TCON_TR1__RUN; 
   TH0      = 0xFE;  // I2C SCL - 333KHz
   TL0      = 0x00;
   TH1      = 0x96;  // Magic values from datasheet for 115200
	TL1      = 0x96;
   // UART
	SCON0    |= SCON0_REN__RECEIVE_ENABLED; 
   // Timer 2
	TMR2CN   = TMR2CN_TR2__RUN;  
   TMR2L    = 0x00;
   TMR2H    = 0xFF;
   TMR2RLL  = 0x00;
   TMR2RLH  = 0xFF;
   // Timer 3
	TMR3CN   = TMR3CN_TR3__RUN;   // ~44 KHz
   TMR3L    = 0x0F;
   TMR3H    = 0xFF;
   TMR3RLL  = 0x0F;
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
   EIE1 = EIE1_ESMB0__ENABLED|
          EIE1_ET3__ENABLED;
   IP   = IP_PT2__HIGH;    
}






