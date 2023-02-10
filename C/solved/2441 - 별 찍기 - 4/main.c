/*
https://www.acmicpc.net/problem/2441
*/

#include <stdio.h>


int main(void){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(j>=i)    printf("*");
            else        printf(" ");
        }
        printf("\n");
    }
    return 0;
}