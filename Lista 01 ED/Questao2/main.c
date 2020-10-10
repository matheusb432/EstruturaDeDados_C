#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i, pos, menor, N;

   scanf("%d", &N);
   int vet[N];
   for(i=0;i<N;i++){ scanf("%d", &vet[i]); }

   menor = vet[0];
   pos = 0;

     for(i=1; i<N; i++)
    {
        if(menor>vet[i])
        {
            menor=vet[i];
            pos=i;
        }
    }
    printf("Menor valor: %d\nPosicao: %d\n", menor, pos);

    return 0;
}

