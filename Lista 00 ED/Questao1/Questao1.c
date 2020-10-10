#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetA[5] = {1,2,3,4,5}, vetB[5] = {5,4,3,2,1}, vetC[10];
    int i = 0, j = 5;

   /* Unindo os vetores A e B no vetor C. */
        for ( i = 0; i < 5; i++ ){
         vetC[i] = vetA[i];
         vetC[j] = vetB[i];
         j++;
     }
    printf("Vetor C: \n\n");
        for ( i = 0; i < 10; i++ )
        if(i == 9){ printf( "%d \n", vetC[i] ); }
        else { printf( "%d, ", vetC[i] ); }
    return 0;
}
