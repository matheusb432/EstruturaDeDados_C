#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int valor;
    struct nodo* proximo;
};
void ler_grafo(struct nodo* ad[], int num_de_nodos);    // funcao void com argumentos ( array de nodos que trata das adjacencias de cada grafo, numero de nodos/vertices desse grafo )
void print_grafo(struct nodo* ad[], int num_de_nodos);


int main()
{
    int i,j,k,nodos;
    printf("Enter the number of nodes: ");
    scanf("%d", &nodos);

    struct nodo* adj[nodos];                           // Definindo um array de ponteiros para structs para as adjacencias do grafo.
    for(i=0;i<nodos;i++){
        adj[i] = NULL;
    }
    ler_grafo(adj,nodos);                              // Chamando as funcoes com os seus devidos argumentos.
    print_grafo(adj,nodos);

    return 0;
}

void ler_grafo(struct nodo* ad[], int num_de_nodos){
    struct nodo* novo_nodo;                            // Definindo um nodo dentro da funcao
    int i, j, k, val;
    for(i=0;i<num_de_nodos;i++){                       // Loop que sera executado conforme o numero de nodos/vertices desse grafo
        struct nodo* ultimo = NULL;
        printf("\n Enter the number of neighbours of %d ", i+1); // i+1 devido a ordenacao padrao computacional, comeca em 0,entao o n-esimo eh i+1
        scanf("%d", &k);  // k = numero de vizinhos, em caso de grafo nao-direcionado, eh o grau desse vertice.
        for(j=0;j<k;j++)  // Loop que executa conforme o numero de vizinhos que esse vertice tem.
        {
            printf("Enter the value of %d -th neighbour of %d: ", j+1, i+1);
            scanf("%d", &val);  // val se trata da vertice que tem adjacencia com a vertice em questao.
            novo_nodo = (struct nodo*)malloc(sizeof(struct nodo*)); // Alocando espaco com malloc()
            novo_nodo->valor = val;    // o valor do struct novo_nodo sera o valor lido no scanf.
            novo_nodo->proximo = NULL; // e o struct nodo* proximo apontara para NULL.
            if(ad[i] == NULL){   // Na primeira instancia do for loop j ==> k, ad[i] = novo_nodo, o nodo eh criado
                ad[i] = novo_nodo;
            }
            else{                             // Mas a partir da segunda instancia desse loop, eh definido no struct nodo* proximo
                ultimo->proximo = novo_nodo;
            }
            ultimo = novo_nodo; // ultimo eh apenas uma variavel auxiliar, que permite a alocacao dos valores do proximo struct.
        }                       // Caso isso e o if/else nao existissem, as adjacencias seriam substituidas a partir da segunda instancia, e seria recordado apenas o ultimo vizinho do grafo.
    }
}

void print_grafo(struct nodo* ad[], int num_de_nodos){
    struct nodo* ptr = NULL;
    int i, j;
    for(i=0;i<num_de_nodos;i++){
        ptr = ad[i];
        printf("\nThe neighbours of %d are: ", i+1);
        while(ptr != NULL){
            printf("%d\t", ptr->valor);
            ptr = ptr->proximo; // quando acabar a lista de adjacências, (*ptr).proximo ira apontar para NULL, e o while terminara.
        }
    }
}

