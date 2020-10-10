#include <stdio.h>
#include <stdlib.h>

struct BstNode {               // bst = binary search tree
    int data;
    struct BstNode* left;      // node* significa ponteiro ao node,
    struct BstNode* right;     // um que guarda o endereco do node da esquerda, e outro da direita
};

struct BstNode* GetNewNode(int data){
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode)); // alocando espaco para a arvore com malloc()
    (*newNode).data = data;                     // Mesmo que newNode->data = data
    (*newNode).left = (*newNode).right = NULL;  // Mesmo que newNode->left = newNode->right = NULL
    return newNode;
  // (*newNode).data = data; ou newNode->data = data ==> desreferencia newNode com *newNode
}

struct BstNode* Insert(struct BstNode* rootPtr, int data){ // struct bstnode* rootptr significa o endereco do nodo da raiz.
    if(rootPtr == NULL){              // Se a raiz esta nula, a arvore esta vazia, o endereco da arvore eh 0 em NULL
        rootPtr = GetNewNode(data);   // Pegar um novo nodo
    }
    else if(data <= rootPtr->data) {   // Se o numero for menor ou igual a raiz, vira um filho na esquerda
        rootPtr->left = Insert(rootPtr->left, data);   // Passando  o endereco do filho da esqueda, e o argumento data
    }
    else {                             // Se o numero for maior que a raiz, vira um filho da direita
        rootPtr->right = Insert(rootPtr->right, data); // Passando  o endereco do filho da direita, e o argumento data
    }
    return rootPtr;  // Retorna o endereco do ponteiro da raiz depois que uma funcao eh executada.
}

int Search(struct BstNode* rootPtr, int data) {   // Fazendo uma funcao de busca, que retornara True caso a data esteja presente no nodo, e False caso contrario.
    if(rootPtr == NULL) {   // Se a raiz esta NULL, deve-se retornar false
        return 0;   // Mesmo que return false;
    }
    else if(rootPtr->data == data) {  // Se a data na raiz eh igual a data que estamos procurando, deve-se retornar true
        return 1;   // Mesmo que return true;
    }
    else if(data <= rootPtr->data) {          // Caso a raiz nao obedecer aos dois condicionais acima, sera usado recursividade para procurar data no filho da esquerda ou da direita
        return Search(rootPtr->left, data);   // Sera executado a funcao e, caso um filho da esquerda ou da direita seja igual a data, o valor sera retornado como true
    }                                         // Caso contrario, sera retornado false.
    else {
        return Search(rootPtr->right, data);
    }
}

int main()
{
    struct BstNode* rootPtr;
    rootPtr = NULL;
    rootPtr = Insert(rootPtr, 15);
    rootPtr = Insert(rootPtr, 10);
    rootPtr = Insert(rootPtr, 20);
    rootPtr = Insert(rootPtr, 05);
    rootPtr = Insert(rootPtr, 30);
    rootPtr = Insert(rootPtr, 25);
    int n;
    printf("Enter number to be searched: \n");
    scanf("%d",&n);
    if(Search(rootPtr, n) == 1) { // Se a funcao retorna 1 (true), o programa informara ao usuario que o valor foi encontrado
        printf("Found\n");
    }
    else {                        // Caso contrario, sera informado que nao foi achado.
        printf("Not Found\n");
    }
    return 0;
}
