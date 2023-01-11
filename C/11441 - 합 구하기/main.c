/*
https://www.acmicpc.net/problem/11441 - 합 구하기
*/

#include <stdio.h>
#include <stdlib.h>




int main(void){
    int N;
    scanf("%d", &N);
    int* arr = (int*)malloc(sizeof(int) * (N+10));
    int* prefixSum = (int*)malloc(sizeof(int) * (N+10));

    int sum = 0;
    for(int i=0;i<N;i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
        prefixSum[i] = sum;
    }

    int M;
    scanf("%d", &M);
    int from, to;
    for(int i=0;i<M;i++){
        scanf("%d %d", &from, &to);
        int sum_from;
        int sum_to;
        if(from == 1){
            sum_from = 0;
        }else{
            sum_from = prefixSum[from-2];
        }
        sum_to = prefixSum[to-1];

        printf("%d\n", sum_to - sum_from);
    }

    free(arr);
    free(prefixSum);
    return 0;
}