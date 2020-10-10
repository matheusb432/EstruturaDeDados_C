#include <stdio.h>
#include <stdlib.h>

int main()
{
       int aux, i, j, N;
		scanf("%d", &N);
        while (N != 0){
            for(i=1;i<=N;i++){
             for(j=1;j<=N;j++){
               aux=i;
               if(j < aux) { aux = j; }
               if(N-i+1 < aux) { aux = N - i + 1; }
               if(N-j+1 < aux) { aux = N - j + 1; }
                    printf("%3d",aux);
               if(N == j) { printf("\n"); }
               else{ printf(" "); }
             }
            }
            printf("\n");
           scanf("%d", &N);
         aux=1;
		}

    return 0;
}
