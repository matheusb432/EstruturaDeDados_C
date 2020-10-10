#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int valor;
    struct nodo* esq;
    struct nodo* dir;
};

struct nodo* criarNovoNodo(int valor){
    struct nodo* novoNodo = (struct nodo*)malloc(sizeof(struct nodo)); // Utilizando malloc para alocar espaco dinamicamente para o novo nodo.
    novoNodo->valor = valor;   // Estabelecendo o novo nodo, definindo valor como a raiz desse nodo
    novoNodo->esq = NULL;      // Ambos os filhos estao vazios, pois, pois nao foram inseridos valores neles ainda.
    novoNodo->dir = NULL;
    return novoNodo;
}

struct nodo* inserir(struct nodo* raizPtr, int valor){
    if(raizPtr == NULL){
        raizPtr = criarNovoNodo(valor);  // Caso a arvore esteja vazia, criar nodo na raiz.
    }
    else if(valor <= raizPtr->valor){
        raizPtr->esq = inserir(raizPtr->esq,valor);
    }
    else if(valor > raizPtr->valor){
        raizPtr->dir = inserir(raizPtr->dir,valor);
    }
    return raizPtr;
}

void preOrdem(struct nodo* raizPtr){
    if(raizPtr == NULL) return;
    printf(" %d", raizPtr->valor);
    preOrdem(raizPtr->esq);
    preOrdem(raizPtr->dir);
}

void emOrdem(struct nodo* raizPtr){
    if(raizPtr == NULL) return;
    emOrdem(raizPtr->esq);
    printf(" %d", raizPtr->valor);
    emOrdem(raizPtr->dir);
}


void posOrdem(struct nodo* raizPtr){
    if(raizPtr == NULL) return;
    posOrdem(raizPtr->esq);
    posOrdem(raizPtr->dir);
    printf(" %d", raizPtr->valor);
}


int main(){
    struct nodo* raiz;
    raiz = NULL;
    int numValores, aux, numArvores, i;
    char space;
    scanf("%d", &numArvores);
    for(i=0;i<numArvores;i++){
        raiz = NULL;
        scanf("%d", &aux);
            while(2 == scanf("%d%c", &numValores, &space)){
                raiz = inserir(raiz,numValores);
            if(space == '\n')
                break;
            }
        printf("Case %d:", i+1);
        printf("\nPre.:");   preOrdem(raiz);
        printf("\nIn..:");   emOrdem(raiz);
        printf("\nPost:");   posOrdem(raiz);
        printf("\n\n");
    }
      return 0;
    }
