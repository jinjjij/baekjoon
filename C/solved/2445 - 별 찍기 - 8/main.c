/*
https://www.acmicpc.net/problem/2445
*/

#include <stdio.h>


int main(void){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        for(int j=0;j<i+1;j++)          printf("*");
        for(int j=0;j<2*(N-i-1);j++)    printf(" ");
        for(int j=0;j<i+1;j++)          printf("*");
        printf("\n");
    }
    for(int i=N-2;i>=0;i--){
        for(int j=0;j<i+1;j++)          printf("*");
        for(int j=0;j<2*(N-i-1);j++)    printf(" ");
        for(int j=0;j<i+1;j++)          printf("*");
        printf("\n");
    }
    return 0;
}