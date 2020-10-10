#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, C;
    char T[2];
    float media, soma=0, M[12][12];

    scanf("%d", &C );
    scanf("%s", &T);

    for(i=0;i<12;i++){
        for(j=0;j<12;j++){
            scanf("%f", &M[i][j]);
           if(j == C){ soma += M[i][j]; }
      }
    }
   media = soma/12;
   if(T[0] == 'S')  { printf("%.1f\n", soma); }
   else { printf("%.1f\n", media); }
    return 0;
}
