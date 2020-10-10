#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    int i, aux, somaM=0, somaF=0;
    setlocale(LC_ALL, "Portuguese");
    struct funcionario {
    char nome[35];
    char sexo[2];
    int Npecas;
    };
    struct funcionario f[4];
    strcpy(f[0].nome, "Thiago");
    strcpy(f[0].sexo, "M");
    f[0].Npecas = 5;

    strcpy(f[1].nome, "Marta");
    strcpy(f[1].sexo, "F");
    f[1].Npecas = 6;

    strcpy(f[2].nome, "Fernanda");
    strcpy(f[2].sexo, "F");
    f[2].Npecas = 3;

    strcpy(f[3].nome, "Jorge");
    strcpy(f[3].sexo, "M");
    f[3].Npecas = 5;

   int maior = f[0].Npecas;

    for(i=0; i<4; i++){
        if(strcmp(f[i].sexo,"M")==0){
         somaM += f[i].Npecas;
        }
   else if(strcmp(f[i].sexo,"F")==0){
         somaF += f[i].Npecas;
        }
        if(maior<f[i].Npecas)  {
                maior=f[i].Npecas;
                aux = i;
        }
    }
    printf("\n Peças produzidas pelos funcionários do sexo masculino: %d", somaM);
    printf("\n Peças produzidas pelos funcionários do sexo feminino: %d", somaF);
    printf("\n Nome do(a) funcionário(a) com a maior produção registrada: %s \n", f[aux].nome);

    return 0;
}
