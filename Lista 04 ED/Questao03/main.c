#include <stdlib.h>
#include <stdio.h>

int main(){

char diamante[1000];
int i, x, n,j=0,k=0,l=0;

scanf("%d", &n);
int D[n];

for(x=0;x<n;x++){
  scanf("%s", &diamante);
  l=0; j=0; k=0;
   for(i=0;i<1000;i++){
       if(diamante[i] == '\0') {
           break;
       }
       if(diamante[i] == '<'){
           j++;
       }
       if(diamante[i] == '>' && j >= 1){
           l++;
           j--;
       }
    }
    if(x >= 0){
        D[x] = l;
     if(x == (n-1)){
      for(i=0;i<n;i++){
      printf("%d\n", D[i]);
      }
     }
  }
  }
    return 0;
}
