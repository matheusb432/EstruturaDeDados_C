#include <stdio.h>
#include <stdlib.h>

   int main()
   {
     int i, x, N;
     unsigned long long int fibbo[61];
     fibbo[0] = 0;
     fibbo[1] = 1;
     scanf("%d", &x);
     for(i=2;i<61;i++){
      fibbo[i] = fibbo[i-1] + fibbo[i-2];
     }

      for(i=0;i<x;i++){
             scanf("%d", &N);
             printf("Fib(%d) = %llu\n", N, fibbo[N]);
     }
     return 0;
   }
