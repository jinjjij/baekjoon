/*
https://www.acmicpc.net/problem/10986
*/

#include <stdio.h>
#include <stdlib.h>


int main(void){
    int N,M;
    scanf("%d %d", &N, &M);
    int* prefix = (int*)malloc(sizeof(int) * N);
    int temp;
    int sum = 0;
    for(int i=0;i<N;i++){
        scanf("%d", &temp);
        sum += temp%M;
    }


    free(prefix);
    return 0;
}