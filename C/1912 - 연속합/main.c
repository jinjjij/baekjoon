/*
https://www.acmicpc.net/problem/1912 - 연속합
*/


#include <stdio.h>





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
    
    free(arr);
    free(prefixSum);
    return 0;
}