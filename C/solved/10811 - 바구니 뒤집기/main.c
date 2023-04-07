/*
https://www.acmicpc.net/problem/10811
*/

#include <stdio.h>


void reverseBasket(int* arr, int a, int b){
    int temp[100];
    
    for(int i=a;i<=b;i++){
        temp[i-a] = arr[i];
    }

    for(int i=a;i<=b;i++){
        arr[i] = temp[b-i];
    }
    
}


int main(void){
    int N,M;
    int arr[102] = {0,};
    scanf("%d %d", &N, &M);

    for(int i=1;i<=N;i++){
        arr[i] = i;
    }

    int a, b;
    for(int i=0;i<M;i++){
        scanf("%d %d", &a, &b);
        reverseBasket(arr, a, b);
    }

    for(int i=1;i<=N;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}