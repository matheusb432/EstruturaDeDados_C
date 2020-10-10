#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("\nEnter numbers: ");
    int sum =0, temp;
    char ch;
    while(2 == scanf("%d%c", &temp, &ch)){
        sum+=temp;
        if(ch == '\n')
            break;
        else if(ch != ' '){
            fprintf(stderr, "Invalid input.\n");
            return -1;
        }
    }
    printf("Sum: %d\n", sum);
    return 0;
}
