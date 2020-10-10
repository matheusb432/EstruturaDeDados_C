#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE 100
using namespace std;
// Representar o grafo como uma matriz ( matriz de adjacencia ) facilita a execução de seu código de maneira eficiente se o grafo for denso, e consome O(v^2) de espaco, onde v sao as vertices
// Construir uma matriz com apenas os 1's salva espaco caso o grafo for escasso, no caso criando 8 arrays com tamanho referente as suas conexões, tornando a complexidade O(e), onde e sao as arestas.
// Complexidade de busca linear = O(v), Complexidade de busca binaria = O(log v)

struct Node{
    int data;
    struct Node* next;
//  int weigth; caso for um grafo com custos.
};
struct Node *A[8]; // Usando listas encadeadas, se cria um array de ponteiros para representar o grafo.
// Todo elemento desse array esta apontando para um nodo.
// Esse metodo se chama de lista de adjacência.


struct Edge{
    int startVertex;   // Melhor nomes sao *firstVertex e secondVertex para grafos nao-direcionados
    int endVertex;     // e *startVertex e *endVertex para grafos direcionados
    int weight;
};

struct Edge edge_list[MAX_SIZE];

int main()
{

    return 0;
}
