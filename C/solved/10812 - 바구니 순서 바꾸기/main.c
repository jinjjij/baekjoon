/*
https://www.acmicpc.net/problem/10812
*/

#include <stdio.h>


void rotateBasket(int* arr, int beg, int end, int mid){
    int temp[110];
    int tmpIdx = beg;
    int Idx = mid;

    while(1){
        temp[tmpIdx++] = arr[Idx++];
        if(Idx > end)   Idx = beg;
        if(Idx == mid)  break;
    }

    for(int i=beg;i<=end;i++){
        arr[i] = temp[i];
    }
}


int main(void){
    int N,M;
    scanf("%d %d", &N, &M);

    int arr[110] = {0,};
    for(int i=0;i<N+1;i++){
        arr[i] = i;
    }

    int a,b,c;
    for(int i=0;i<M;i++){
        scanf("%d %d %d", &a, &b, &c);
        rotateBasket(arr, a,b,c);
    }

    for(int i=0;i<N;i++){
        printf("%d ", arr[i+1]);
    }
    return 0;
}