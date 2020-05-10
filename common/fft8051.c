#include "fft8051.h"
#include "Ws.h"

void fft(complex_t * a){
   static unsigned char i,j,k,Wi;
   static unsigned short x,y;
   static complex_t m; 
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
            Wi = (j * y) % N_2;
            // Move over the points
            // of interest from 
            // external ram
            k = j | x; 
            // Butterfly of
            // complex numbers 
            m.re = (short)((Wreal[Wi] * a[k].re) - (Wimag[Wi] * a[k].im));
            m.im = (short)((Wreal[Wi] * a[k].im) + (Wimag[Wi] * a[k].re));  
            a[k].re = a[j].re - m.re;
            a[k].im = a[j].im - m.im;
            a[j].re = a[j].re + m.re;
            a[j].im = a[j].im + m.im;         
         }
      }
      // * 2
      x <<= 1;
      // / 2
      y >>= 1;
   }
   return; 
}

unsigned char mag(complex_t * a){
   static float s, sqrt, p0_sqrt, p1_sqrt;
   // Square and sum
   s = (float)(a->re) * (float)(a->re);
   s += (float)(a->im) * (float)(a->im); 
   // Converge on the square root
   sqrt    = s / 2;
   p0_sqrt = 0; 
   p1_sqrt = 0;
   while((sqrt != p1_sqrt) &&
         (sqrt != p0_sqrt)){   
      p1_sqrt = p0_sqrt;
      p0_sqrt = sqrt;
      sqrt    = ((s / sqrt) + sqrt) / 2; 
   }
   return (unsigned char)(sqrt/N_2);
}
