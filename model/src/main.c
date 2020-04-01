#include <stdio.h>
#include "fft8051.h"

int main(int argc, char *argv[]){
   unsigned char i;
   complex_t t[N];
   for(i=0;i<N;i++){
      t[i].re = (i % 2);
      t[i].im = 0;
   }
   fft(t);
   for(i=0;i<N-1;i++){
      printf("%d,", mag(&t[i]));
   }
   printf("%d\n\r", mag(&t[N-1]));
   return 0;
}
