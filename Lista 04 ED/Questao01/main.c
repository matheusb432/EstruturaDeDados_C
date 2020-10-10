#include<stdio.h>
#include<stdlib.h>
#define TAM 1001

struct pilha{
   int v[TAM];
   int *top;
};

int peek(struct pilha *p){
   if(p->top > p->v){
      return *(p->top-1);
   }
   else{
      return 0;
   }
}

int pop(struct pilha *p){
   int valor;
   if(p->top > p->v){
      p->top--;
      valor = *(p->top);
      return valor;
   }
   else {
      return 0;
   }
}

int push(struct pilha *p,int valor){
   if(p->top < p->v+TAM){
      *(p->top) = valor;
      p->top++;
      return 1;
   }
   else{
      return 0;
   }
}

int main(){
   int i, n, entrada[TAM], saida[TAM];
   int *in = entrada, *out = saida;

   struct pilha p;
   p.top = p.v;
   for(i=0;i<TAM;i++){
      entrada[i] = i+1;
   }

   scanf("%d",&n);
   while(n != 0){
      scanf("%d",&saida[0]);
      if(saida[0]){
     for(i=1;i<n;i++){
        scanf("%d",&saida[i]);
     }
     in = entrada;
     out = saida;
     while(in<entrada+n){
        push(&p,*in);
        in++;
        while(peek(&p) == *out){
           pop(&p);
           out++;
        }
     }
     if(saida+n == out){
            printf("Yes\n");
     }
     else {
            printf("No\n");
     }
     p.top = p.v;
      }
      else{
     scanf("%d",&n);
     if(n != 0){
        printf("\n");
        p.top = p.v;
     }
      }
   }
   return 0;
}
