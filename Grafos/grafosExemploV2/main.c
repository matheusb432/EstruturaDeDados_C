#include <stdio.h>
#include <stdlib.h>

struct vertice {
    int valor;
    struct vertice* proximo;
};

void ler_grafo(struct vertice* adjacencias[], int num_vertices);
void printar_grafo(struct vertice* adjacencias[], int num_vertices);

int main()
{
    int i, num_vertex;
    printf("Quantas vertices tem o grafo: ");
    scanf("%d", &num_vertex);
    struct vertice* adj[num_vertex];

    for(i=0;i<num_vertex;i++){
        adj[i] = NULL;
    }
    ler_grafo(adj,num_vertex);
    printar_grafo(adj,num_vertex);
    return 0;
}

void ler_grafo(struct vertice* adjacencias[], int num_vertices){
    struct vertice* novo_vertice;
    int i, j, numVizinhos,valor;
    for(i=0;i<num_vertices;i++){
        struct vertice* ultimo = NULL;
        printf("Quantos vizinhos tem a vertice %d? ", i+1);
        scanf("%d", &numVizinhos);
        for(j=0;j<numVizinhos;j++){
            printf("Qual o %d -esimo vizinho de %d? ", j+1,i+1);
            scanf("%d", &valor);
            novo_vertice = (struct vertice*)malloc(sizeof(struct vertice*));  // É necessario alocar espaco a cada loop, se nao os outros loops irao sobscrever o primeiro.
            novo_vertice->valor = valor;
            novo_vertice->proximo = NULL;
            if(adjacencias[i] == NULL){
                adjacencias[i] = novo_vertice;
            }
            else{
                ultimo->proximo = novo_vertice;
            }
            ultimo = novo_vertice;
        }
    }
}
void printar_grafo(struct vertice* adjacencias[], int num_vertices){
    struct vertice* ptr = NULL;
    int i,j,numVizinhos;

    for(i=0;i<num_vertices;i++){
        if(adjacencias[i] != NULL){
            numVizinhos++;
        }
    }
    for(i=0;i<num_vertices;i++){
        ptr = adjacencias[i];
        printf("\nAdjacencias da vertice %d: ", i+1);
        for(j=0;j<numVizinhos;j++){
            if(ptr != NULL){
              printf("%d  ", ptr->valor);
              ptr = ptr->proximo;
            }
        }
    }
}
//
/*
void printar_grafo(struct vertice* adjacencias[], int num_vertices){
    struct vertice* ptr = NULL;
    int i,j,numVizinhos;

    for(i=0;i<num_vertices;i++){
        if(adjacencias[i] != NULL){
            numVizinhos++;
        }
    }
    for(i=0;i<num_vertices;i++){
        ptr = adjacencias[i];
        printf("\nAdjacencias da vertice %d: ", i+1);
      //  for(j=0;j<numVizinhos+1;j++){
            while(ptr != NULL){
              printf("%d  ", ptr->valor);
              ptr = ptr->proximo;
            }
      //      else break;
      //  }
    }
} */
