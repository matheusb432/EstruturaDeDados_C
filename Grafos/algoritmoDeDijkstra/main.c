#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <limits.h>  // Biblioteca que permite o uso de infinito ( INT_MAX )
#define MAX 1000

struct vertice{
    int valor;
    struct vertice* prox_vertice;
};

struct aresta{
    int valorI;
    int valor;
    int distancia;
    struct aresta* prox_aresta;
};
struct aresta* grafo1[MAX][MAX];

void ler_grafo(struct vertice* grafo[], int num_de_vertices){
    struct vertice* novo_vertice;
    struct vertice* ultimo;
    int i, j, vizinhos, valor;
    for(i=0;i<num_de_vertices; i++){
        ultimo = NULL;
        printf("Insira a quantidade de vizinhos da vértice %d: ", i);
        scanf("%d",&vizinhos);
        for(j=0;j<vizinhos;j++){
            printf("Insira o vizinho número %d da vértice %d: ", j, i);
            scanf("%d", &valor);
            novo_vertice = (struct vertice*)malloc(sizeof(struct vertice));
            novo_vertice->valor = valor;
            novo_vertice->prox_vertice = NULL;
            if(grafo[i] == NULL){
                grafo[i] = novo_vertice;  // Armazena, no indice i do grafo, a vertice no primeiro loop, e nos loops subsequentes, guardara o endereco de todas as adjacencias desse grafo.
            }
            else{
                ultimo->prox_vertice = novo_vertice;
            }
            ultimo = novo_vertice;
        }
    }

}

void definir_distancia(struct vertice* grafo[], int num_de_vertices){
    struct aresta* nova_aresta;
    struct aresta* ultima;
    struct vertice* ptr;
    int i,aux=0;
    for(i=0;i<num_de_vertices;i++){
    //    ultima = NULL;
        ptr = grafo[i];
        while(ptr != NULL){
            printf("\nDefina a distancia entre as vertices [%d,%d]: ", i, ptr->valor);
            nova_aresta = (struct aresta*)malloc(sizeof(struct aresta));
            scanf("%d", &nova_aresta->distancia);
            nova_aresta->valorI = i;
            nova_aresta->valor = ptr->valor;
            nova_aresta->prox_aresta = NULL;

            grafo1[i][ptr->valor] = nova_aresta;
            nova_aresta = nova_aresta->prox_aresta;
            printf("\nDistancia entre [%d,%d]: %d\n", grafo1[i][ptr->valor]->valorI, grafo1[i][ptr->valor]->valor, grafo1[i][ptr->valor]->distancia);
            ptr = ptr->prox_vertice;
        }
    }
}

void dijkstra(int num_de_vertices){
    int i, j, aux=0, ponto_inicial, menor_caminho,prox_vertice;
    int visitado[10], distancia[10],predecessor[10];
    int matriz_distancia[10][10]= {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(grafo1[i][j] != NULL){
                matriz_distancia[i][j] = grafo1[i][j]->distancia;
            }
        }
    }

    for(i=0;i<num_de_vertices;i++){
            printf("\n");
        for(j=0;j<num_de_vertices;j++){
            printf("%d\t", matriz_distancia[i][j]);
        }
    }

    printf("\nDigite o ponto inicial que o algoritmo precisará percorrer: ");
    scanf("%d", &ponto_inicial);
    printf("\nPonto inicial = %d", ponto_inicial);

    for(i=0;i<num_de_vertices;i++){
        for(j=0;j<num_de_vertices;j++){
            if(matriz_distancia[i][j] == 0){
                matriz_distancia[i][j] = INT_MAX/2;
            }
        }
    }

    for(i=0;i<num_de_vertices;i++)
    {
        distancia[i] = matriz_distancia[ponto_inicial][i];
        predecessor[i] = ponto_inicial;
        visitado[i] = 0;
    }

    distancia[ponto_inicial] = 0;
    visitado[ponto_inicial] = 1;
    aux=1;
    for(i=0;i<num_de_vertices-1;i++)
	{
		menor_caminho=INT_MAX/2;
		for(j=0;j<num_de_vertices;j++)
        {
			if(distancia[j]<menor_caminho && visitado[j]==0)
			{
				menor_caminho=distancia[j];
				prox_vertice=j;
			}
        }
			visitado[prox_vertice]=1;
			for(j=0;j<num_de_vertices;j++)
			{
                    if(visitado[j] == 0)
                    {
                        if(menor_caminho + matriz_distancia[prox_vertice][j]<distancia[j])
                        {
                            distancia[j]=menor_caminho + matriz_distancia[prox_vertice][j];
                            predecessor[j]=prox_vertice;
                        }
                    }
			}
	}
	for(i=0;i<num_de_vertices;i++)
    {
		{
			printf("\n\nDistância para a vértice %d = %d",i,distancia[i]);
			printf("\nCaminho percorrido = %d",i);

			aux=i;

			do
			{
				aux=predecessor[aux];
				printf(" <- %d",aux);
			}while(aux != ponto_inicial);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int i, aux=1, num_de_vertices;

    printf("Insira o numero de vertices que o grafo terá: ");
    scanf("%d", &num_de_vertices);
    struct vertice* grafoLocal[num_de_vertices];
    for(i=0;i<num_de_vertices;i++){
        grafoLocal[i] = NULL;
    }
    ler_grafo(grafoLocal,num_de_vertices);
    definir_distancia(grafoLocal,num_de_vertices);
    dijkstra(num_de_vertices);

    return 0;
}
