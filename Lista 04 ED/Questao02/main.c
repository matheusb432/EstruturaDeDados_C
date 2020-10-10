#include <stdlib.h>
#include <stdio.h>

int main(){
    char expressao[1000];
    int i, j, k;
       while(scanf("%s",&expressao) != EOF){
       j = 0; k = 0;
       for(i = 0; expressao[i] != '\0'; i++){
             if(expressao[i] == '(') j++;
             else if (expressao[i] == ')'){
                  k++;
                  if(j > 0){
                  j--;  k--;
                  }
             }
       }
       if(j == 0 && k == 0) printf("correct\n");
       else printf("incorrect\n");
       }
    return 0;
}
/*
int main(){

char expressao[1000];
int i, x, n,j=0,k=0;

scanf("%d", &n);

for(x=0;x<n;x++){
  scanf("%s", &expressao);
   j=0; k=0;
   for(i=0;expressao[i]!='\0';i++){
       if(expressao[i] == '('){
           j++;
       }
       else if(expressao[i] == ')'){
           k++;
           if(j>0){
            j--;
            k--;
           }

       }

     }
        if(x == (n-1)){
      for(i=0;i<x;i++){

            if( j == 0 && k == 0) printf("Correct\n");
            else printf("Incorrect\n");
      }
  }
    }


    return 0;
}
 */
