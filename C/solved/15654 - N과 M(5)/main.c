/*
https://www.acmicpc.net/problem/15654
*/

#include <stdio.h>
#include <stdlib.h>



void dfs(int* arr, int* vis, int N, int lev, int* resultArr, int resultSize){
    if(lev==0){
        for(int i=0;i<resultSize;i++){
            printf("%d ", resultArr[i]);
        }
        printf("\n");
        return;
    }
    for(int i=0;i<N;i++){
        if(!vis[i]){
            vis[i] = 1;
            resultArr[resultSize] = arr[i];
            dfs(arr, vis, N, lev-1, resultArr, resultSize+1);
            vis[i] = 0;
        }
    }
}


int compare(const void* arg1, const void* arg2){
    return *(int*)arg1 - *(int*)arg2;
}


int main(void){
    int N,M;
    scanf("%d %d", &N, &M);
    int* arr = (int*)malloc(sizeof(int) * N);
    int* vis = (int*)malloc(sizeof(int) * N);
    int* result = (int*)malloc(sizeof(int) * M);

    for(int i=0;i<N;i++){
        scanf("%d", &arr[i]);
        vis[i] = 0;
    }
    qsort(arr, N, sizeof(int), compare);

    dfs(arr, vis, N, M, result, 0);


    free(result);
    free(vis);
    free(arr);
    return 0;
}