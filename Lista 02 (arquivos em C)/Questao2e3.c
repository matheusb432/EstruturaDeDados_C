#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    int i, j, aux;
    setlocale(LC_ALL, "Portuguese");
    struct aluno {
    char nome[35];
    int nota[3];
    };
    struct aluno a[35];

    for(i=0;i<35;i++){
        scanf("%s", &a[i].nome);
        for(j=0;j<3;j++){
            scanf("%d", &a[i].nota[j]);
        }
    }
    getch();
    printf("\n\n");

    for(i=0;i<35;i++){
        printf("Nome: %s \n", a[i].nome);
        aux=1;
        for(j=0;j<3;j++){
                if(j==2) { printf("Nota AF: %d \n\n", a[i].nota[j]); }
            else {
                    printf("Nota AP%d: %d \n", aux, a[i].nota[j]);
                    aux++;
             }
        }
    }
    return 0;
}
