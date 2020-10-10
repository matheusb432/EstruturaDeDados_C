#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct tipoItem {
  int chave;
};

typedef struct no *apontador; 	// define o tipo "apontador" como sendo o
				// endere�o de um "no" ou "vertice"
struct no {
  tipoItem item;
  apontador esq;
  apontador dir;
};

void insere(tipoItem x, apontador *p);
void inserirNos(apontador *raiz);

void visitaRaiz(apontador no);
void pre_ordem(apontador p);
void em_ordem(apontador p);
void pos_ordem(apontador p);
void caminhamentos(apontador raiz, int op);

void antecessor(apontador q, apontador *r);
void retira(tipoItem x, apontador *p, int *operacao);
void removerNos(apontador *raiz);

void main() {
  apontador raiz;
  int op;

  raiz = NULL; // inicializa a arvore

  do {
    clrscr();
    gotoxy(10,  5); printf("MENU PRINCIPAL - Arvore Binaria de Pesquisa");
    gotoxy(10,  6); printf("[ 1 ] Inserir nos na Arvore");
    gotoxy(10,  7); printf("[ 2 ] Remover nos da Arvore");
    gotoxy(10,  8); printf("[ 3 ] Caminhamento pre-ordem (R E D)");
    gotoxy(10,  9); printf("[ 4 ] Caminhamento em-ordem (E R D)");
    gotoxy(10, 10); printf("[ 5 ] Caminhamento pos-ordem (E D R)");
    gotoxy(10, 11); printf("[ 0 ] Encerrar o programa");
    gotoxy(10, 12); printf("[ ? ] Opcao Desejada");

    do {
      gotoxy(12, 12); scanf("%d", &op);
    } while ((op < 0) || (op > 5));

    switch (op) {
      case 1: inserirNos(&raiz); break;
      case 2: removerNos(&raiz); break;
      case 3: caminhamentos(raiz, op); break;
      case 4: caminhamentos(raiz, op); break;
      case 5: caminhamentos(raiz, op);
    }

  } while (op != 0);
}

void insere(tipoItem x, apontador *p) {
  if ((*p) == NULL) {
     *p = (apontador) malloc(sizeof(no));
     (*p)->item = x;
     (*p)->esq = NULL;
     (*p)->dir = NULL;
  }
  else if (x.chave < (*p)->item.chave)
	  insere(x, &((*p)->esq));
       else insere(x, &((*p)->dir));
}

void inserirNos(apontador *raiz) {
  tipoItem x;
  while (1) {
    clrscr();
    printf("Informe um item a ser inserido, -1 para encerrar:\n");
    scanf("%d", &x.chave);
    if (x.chave == -1)
       break;

    insere(x, raiz);
  }
}

void visitaRaiz(apontador no) {
  printf("%d ", no->item.chave);
}

void pre_ordem(apontador p) {
  if (p != NULL) {
     visitaRaiz(p);
     pre_ordem(p->esq);
     pre_ordem(p->dir);
  }
}

void em_ordem(apontador p) {
  if (p != NULL) {
     em_ordem(p->esq);
     visitaRaiz(p);
     em_ordem(p->dir);
  }
}

void pos_ordem(apontador p) {
  if (p != NULL) {
     pos_ordem(p->esq);
     pos_ordem(p->dir);
     visitaRaiz(p);
  }
}

void caminhamentos(apontador raiz, int op) {
  clrscr();
  switch (op) {
    case 3: {
      printf("Caminhamento pre-ordem, ou pre-fixado (R E D):\n");
      pre_ordem(raiz);
      break;
    }
    case 4: {
      printf("Caminhamento central (em-ordem), ou infixado (E R D):\n");
      em_ordem(raiz);
      break;
    }
    case 5: {
      printf("Caminhamento pos_ordem, ou pos_fixado (E D R):\n");
      pos_ordem(raiz);
    }
  }
  printf("\n\nPressione [algo] para prosseguir.");
  getch();
}

void antecessor(apontador q, apontador *r) {
  if ((*r)->dir != NULL)
     antecessor(q, &((*r)->dir));
  else {
     q->item = (*r)->item;
     q = *r;
     *r = (*r)->esq;
     free(q);
  }
}

void retira(tipoItem x, apontador *p, int *operacao) {
  apontador aux;
  if ((*p) == NULL)
     *operacao = 0;
  else if (x.chave < (*p)->item.chave)
	  retira(x, (&(*p)->esq), operacao);
       else if (x.chave > (*p)->item.chave)
	       retira(x, (&(*p)->dir), operacao);
	    else {
	       *operacao = 1;
	       if ((*p)->dir == NULL) {
		  aux = *p;
		  *p = (*p)->esq;
		  free(aux);
	       }
	       else if ((*p)->esq == NULL) {
		       aux = *p;
		       *p = (*p)->dir;
		       free(aux);
	            }
		    else antecessor((*p), (&(*p)->esq));
	    }
}

void removerNos(apontador *raiz) {
  tipoItem x;
  int operacao;
  while (1) {
    clrscr();
    printf("Informe um item a ser removido, -1 para encerrar:\n");
    scanf("%d", &x.chave);
    if (x.chave == -1)
       break;

    retira(x, raiz, &operacao);

    if (operacao == 1)
       printf("\n\nItem removido com sucesso !!!");
    else printf("\n\nErro: Registro nao encontrado.");

    printf("\n\nPressione [algo] para prosseguir.");
    getch();
  }
}
