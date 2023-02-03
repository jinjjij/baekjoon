/*
https://www.acmicpc.net/problem/15663
*/

#include <stdio.h>
#include <stdlib.h>



int N,M;
int arr[10];
int result[10];
int visited[10];


int compare(const void* arg1, const void* arg2){
    return *(int*)arg1 - *(int*)arg2;
}


void dfs(int lev, int resultIndex){
    int prev = -1;
    if(lev==0){
        for(int i=0;i<M;i++)    printf("%d ", result[i]);
        printf("\n");
        return;
    }

    for(int i=0;i<N;i++){
        if(!visited[i] && arr[i]!=prev){
            visited[i] = 1;
            prev = arr[i];
            result[resultIndex] = arr[i];
            dfs(lev-1, resultIndex+1);
            visited[i] = 0;
        }
    }
}


int main(void){
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++){
        scanf("%d", &arr[i]);
        visited[i] = 0;
    }
    qsort(arr, N, sizeof(int), compare);
    dfs(M, 0);
    return 0;
}