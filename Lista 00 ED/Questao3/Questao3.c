#include <stdio.h>
#include <stdlib.h>

int Antecessores (int n){
   static int vet[2];
   vet[0] = n - 1;
   vet[1] = n - 2;
   return(vet);
}

int Successores (int n){
    static int vet[2];
   vet[0] = n + 1;
   vet[1] = n + 2;
   return(vet);
}

int main()
{
   int N, *vetor, ant1, ant2, suc1, suc2;

   printf("Insira um numero N: \n");
   scanf("%d", &N);

   vetor = Antecessores(N);
   ant1 = vetor[0];
   ant2 = vetor[1];
   printf("\n Antecessores de N: %d , %d \n ", ant1, ant2);

   vetor = Successores(N);
   suc1 = vetor[0];
   suc2 = vetor[1];
   printf("Successores de N: %d , %d", suc1, suc2);


    return 0;
}
