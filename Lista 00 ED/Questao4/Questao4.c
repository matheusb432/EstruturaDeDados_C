#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, matA[5][4], matB[4][3], matC[5][4] = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};

  printf ("Insira valores para os elementos da matriz A: \n");

  for ( i=0; i<5; i++ ){
    for ( j=0; j<4; j++ )
    {
      printf ("\nElemento[%d][%d] = ", i, j);
      scanf ("%d", &matA[i][j]);
    }
  }
    printf ("\nInsira valores para os elementos da matriz B: \n");

  for ( i=0; i<4; i++ ){
    for ( j=0; j<3; j++ )
    {
      printf ("\nElemento[%d][%d] = ", i, j);
      scanf ("%d", &matB[i][j]);
    }
  }
	for( i=0;i<5;i++ ){
		for( j=0;j<4;j++ ){
			 for( k=0;k<3;k++ ){
				matC[i][j] = matC[i][j] + (matA[i][k] * matB[j][k]);
			}


	}
	}
	 getch();
	 printf("\n\n Matriz C: \n\n");
  for ( i=0; i<5; i++ ){
   for ( j=0; j<4; j++ )
    {
      printf ("\nElemento[%d][%d] = %d\n", i, j, matC[i][j]);
    }
  }
    return 0;
}
