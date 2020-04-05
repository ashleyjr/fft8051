#include <stdio.h>
#include "fft8051.h"

int main(int argc, char *argv[]){
   unsigned char i;
   complex_t t[N]; 
   if(argc != (1 + N)){
      printf("ERROR\n\r");
      return 1;
   }
   for(i=0;i<N;i++){
      t[i].re = atoi(argv[i]);
      t[i].im = 0;
   }
   fft(t);
   for(i=0;i<N-1;i++){
      printf("%d,", mag(&t[i]));
   }
   printf("%d\n\r", mag(&t[N-1]));
   return 0;
}
