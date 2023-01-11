/*
https://www.acmicpc.net/problem/2110 - 공유기 설치


*/

#include <stdio.h>


int main(void){
    int N, C;

    scanf("%d %d", &N, &C);

    int* house = (int*)malloc(sizeof(int) * N);

    for(int i=0;i<N;i++){
        scanf("%d", &house[i]);
    }


    free(house);
    return 0;
}