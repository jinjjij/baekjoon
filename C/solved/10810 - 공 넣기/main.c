/*
https://www.acmicpc.net/problem/10810
*/

#include <stdio.h>



void addBall(int* arr, int from, int to, int ball){
    for(int i=from; i<= to; i++){
        arr[i] = ball;
    }
}


int main(void){
    int N,M;
    int arr[102] = {0,};
    scanf("%d %d", &N, &M);
    int f,t,b;
    for(int i=0;i<M;i++){
        scanf("%d %d %d", &f, &t, &b);
        addBall(arr, f, t, b);
    }

    for(int i=1;i<=N;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}