#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    int i, aux=1, aux2;
    char S_aux[35];
    setlocale(LC_ALL, "Portuguese");
    struct agenda {
    char nome[35];
    char end[35];
    char tel[15];
    char sit[2];
    };
    struct agenda p[5];


    while(aux!=0){
        // system("cls");
     printf("1. Inserir Dados dos 5 registros \n2. Pesquisar o nome para acessar um dos registros \n3. Alterar dados de um dos registros \n0. Sair do programa.\n");
     scanf("%d", &aux);
    if( aux == 0) { continue; }

    if( aux == 1) {
    for(i=0;i<2;i++){
        printf("\nInsira o nome, endere�o, telefone e a situa��o do registro p[%d]: \n", i);
        scanf("%s%s%s%s", &p[i].nome, &p[i].end, &p[i].tel, &p[i].sit);
    }
    continue;
    }
    printf("\nInsira o nome da pessoa para alterar seu respectivo registro: ");
    scanf("%s", &S_aux);

    for(i=0; i<5; i++){
        if(strcmp(p[i].nome,S_aux)==0){
         printf("\nDigite 1 para alterar o nome, 2 para alterar o endere�o, 3 para alterar o telefone e 4 para alterar a situa��o deste registro: ");
         scanf("%d", &aux2);
         if(aux2==1){
            printf("\nDigite o novo nome\n");
            scanf("%s", &p[i].nome);
         }
    else if(aux2==2){
           printf("\nDigite o novo endere�o\n");
           scanf("%s", &p[i].end);
         }
    else if(aux2==3){
           printf("\nDigite o novo telefone\n");
           scanf("%s", &p[i].tel);
         }
    else if(aux2==4){
           printf("\nDigite a nova situa��o\n");
           scanf("%s", &p[i].sit);
         }
        printf("\n  Registro novo\nNome: %s\n",p[i].nome);
        printf("\nEndere�o: %s\n",p[i].end);
        printf("\nTelefone: %s\n",p[i].tel);
        printf("\nSitua��o: %s\n\n",p[i].sit);
        }
    }
 }


    return 0;
}
