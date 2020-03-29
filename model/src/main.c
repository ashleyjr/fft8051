#include <stdio.h>
#include "fft8051.h"

int main(int argc, char *argv[]){
  
   char i;
   complex_t in[N];

   for(i=0;i<N;i++){
      in[i].re = i;
      in[i].im = i;
   }
   fft(in);
   for(i=0;i<N;i++){
      printf("%d\n\r", in[i].re);
   }

   return 0;
}
