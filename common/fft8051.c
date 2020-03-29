#include "fft8051.h"

void fft(complex_t * a){
   static unsigned char i,j,k,x,y,Wi;
   static complex_t m,W,p,q;
   // Reorder array
   //    Imaginary part is empty 
   //    at this stage so use it
   //    for the swapping
   for(i=0;i<N;i++){ 
      k = 0;
      // Reverse bits
      for(j = 1; j <= LOG2N; j++) {
         if(i & (1 << (LOG2N - j)))
            k |= 1 << (j - 1);
      }  
      // Move around  
      a[i].im = a[k].re;
   }
   // Correct the labelling
   for(i=0;i<N;i++){
      a[i].re = a[i].im;      
      a[i].im = 0;
   }
   // Indexing in powers of 2
   x = 1;
   y = N_2;
   for(i=0;i<LOG2N;i++) {
      for(j=0;j<N;j++) {
         // Do not match for half 
         // to keep power 2 pattern
         // or with x takes other half
         if(!(x & j)) { 
            // Twiddle index
            Wi = (j * y) % (x * y);
            // Move over the points
            // of interest from 
            // external ram
            k  = j | x; 
            p  = a[j];  
            q  = a[k];
            // Butterfly of
            // complex numbers 
            m.re    = (W.re * q.re) - (W.im * q.im);
            m.im    = (W.re * q.im) + (W.im * q.re); 
            a[j].re = p.re + m.re;
            a[j].im = p.im + m.im;
            a[k].re = p.re - m.re;
            a[k].im = p.im - m.im;
         }
      }
      // * 2
      x <<= 1;
      // / 2
      y >>= 1;
   } 
}
