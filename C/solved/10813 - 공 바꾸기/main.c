/*
https://www.acmicpc.net/problem/10813
*/

#include <stdio.h>


void swapBall(int* arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}


int main(void){
    int N, M;
    scanf("%d %d", &N, &M);

    int arr[110];
    for(int i=1;i<N+1;i++){
        arr[i] = i;
    }

    int a,b;
    for(int i=0;i<M;i++){
        scanf("%d %d", &a, &b);
        swapBall(arr, a, b);
    }

    for(int i=1;i<N+1;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}