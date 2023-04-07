/*
https://www.acmicpc.net/problem/25314
*/

#include <stdio.h>


int main(void){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N/4;i++){
        printf("long ");
    }
    printf("int");
    return 0;
}

// 4-7 : 1
// 8-11: 2