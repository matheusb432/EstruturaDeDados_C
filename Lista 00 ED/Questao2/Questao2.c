#include<stdio.h>
#include<conio.h>
int main ()
{
  int h, i, j, k, matA[5][3], matB[5][3], matC[2][15];

  printf ("Insira valores para os elementos da matriz A: \n");

  for ( i=0; i<5; i++ ){
    for ( j=0; j<3; j++ )
    {
      printf ("\nElemento[%d][%d] = ", i, j);
      scanf ("%d", &matA[i][j]);
    }
  }
    printf ("\nInsira valores para os elementos da matriz B: \n");

  for ( i=0; i<5; i++ ){
    for ( j=0; j<3; j++ )
    {
      printf ("\nElemento[%d][%d] = ", i, j);
      scanf ("%d", &matB[i][j]);
    }
  }
  i = 0;
 getch();
  /* Preenchendo a matriz C com os elementos de ambas as matrizes. */
for(j=0; j<5; j++){
  for(k=0; k<3; k++){
     matC[0][i] = matA[j][k];
    matC[1][i] = matB[j][k];
    i++;

      }
     }

  printf("\n\nMatriz C: \n\n");

  for ( i=0; i<2; i++ ){
    for ( j=0; j<15; j++ )
    {
      printf ("\nElemento[%d][%d] = %d\n", i, j, matC[i][j]);
    }
  }


  getch();

  return 0;
}
