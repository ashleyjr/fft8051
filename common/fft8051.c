#include "fft8051.h"
#include "Ws.h"

void fft(complex_t * a){
   static unsigned char i,j,k,Wi;
   static unsigned short x,y;
   static complex_t m,w,p,q;
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
            w.re = W[Wi].re;
            w.im = W[Wi].im;
            p.re = a[j].re;
            p.im = a[j].im;
            q.re = a[k].re;
            q.im = a[k].im;
            // Butterfly of
            // complex numbers 
            m.re = (((w.re * q.re) - (w.im * q.im))/SCALE);
            m.im = (((w.re * q.im) + (w.im * q.re))/SCALE); 
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
   return; 
}

unsigned long mag(complex_t * a){
   static unsigned long s, sqrt, p0_sqrt, p1_sqrt;
   // Square and sum
   s = (a->re * a->re) + (a->im * a->im); 
   // Converge on the square root
   sqrt    = s >> 1;
   p0_sqrt = 0; 
   p1_sqrt = 0;
   while((sqrt != p1_sqrt) &&
         (sqrt != p0_sqrt)){   
      p1_sqrt = p0_sqrt;
      p0_sqrt = sqrt;
      sqrt    = ((s / sqrt) + sqrt) >> 1; 
   }
   return sqrt;
}
