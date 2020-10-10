#include <stdio.h>
#include <stdlib.h>

struct vertice{
    int valor;
    struct vertice* proximo;
};

void ler_grafo(struct vertice* adj[], int num_nodos){
    struct vertice* novo_vert;
    struct vertice* ultimo;
    int i,j,k,val;
    for(i=0;i<num_nodos;i++){
        ultimo = NULL;
        printf("Insira o numero de adjacencias da vertice %d: ", i+1);
        scanf("%d", &k);
            for(j=0;j<k;j++){
                printf("Insira o vizinho %d do vertice %d: ", j+1, i+1);
                scanf("%d", &val);
                novo_vert = (struct vertice*)malloc(sizeof(struct vertice));
                novo_vert->valor = val;
                novo_vert->proximo = NULL;
                if(adj[i] == NULL){
                    adj[i] = novo_vert;
                }
                else{
                    ultimo->proximo = novo_vert;
                }
                ultimo = novo_vert;
            }
        }
}

void printar_grafo(struct vertice* adj[], int num_nodos){
    struct vertice* ptr;
    int i;
    for(i=0;i<num_nodos;i++){
        ptr = adj[i];
        printf("\nAdjacencias do vertice %d: ", i+1);
        while(ptr != NULL){
            printf("%d\t", ptr->valor);
            ptr = ptr->proximo;
        }
    }
}

int main()
{
    int i,j,num_N;
    printf("Insira o numero de vertices desse grafo: ");
    scanf("%d", &num_N);
    struct vertice* ad[num_N];

    for(i=0;i<num_N;i++){
        ad[i] = NULL;
    }

    ler_grafo(ad,num_N);
    printar_grafo(ad,num_N);

    return 0;
}
