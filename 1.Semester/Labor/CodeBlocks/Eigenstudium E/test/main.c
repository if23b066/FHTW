#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;

    do{
        printf("1. Continue\n");
        printf("2. Quit\n");
        printf("Your selection: \n");
        scanf("%d", &i);

        if(i == 1){
            printf("Let's continue\n");
        }
        else if(i == 2){
            printf("Bye, bye\n");
        }
        else{
            printf("Unknown selection\n");
        }
    } while(i != 2);
    return 0;

}
