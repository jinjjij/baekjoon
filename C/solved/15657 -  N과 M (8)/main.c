/*
https://www.acmicpc.net/problem/15657
*/

#include <stdio.h>
#include <stdlib.h>


int compare(const void* arg1, const void* arg2){
    return *(int*)arg1 - *(int*)arg2;
}


void dfs(int* arr, int arrSize, int prevIndex, int lev, int* resultArr, int resultSize){
    if(lev==0){
        for(int i=0;i<resultSize;i++){
            printf("%d ", resultArr[i]);
        }
        printf("\n");
        return;
    }

    for(int i=prevIndex;i<arrSize;i++){
        resultArr[resultSize] = arr[i];
        dfs(arr, arrSize, i, lev-1, resultArr, resultSize+1);
    }
}


int main(void){
    int N,M;
    scanf("%d %d", &N, &M);
    int* arr = (int*)malloc(sizeof(int) * N);
    int* result = (int*)malloc(sizeof(int) * M);

    for(int i=0;i<N;i++){
        scanf("%d", &arr[i]);
    }
    qsort(arr, N, sizeof(int), compare);

    dfs(arr, N, 0, M, result, 0);

    free(arr);
    free(result);
    return 0;
}