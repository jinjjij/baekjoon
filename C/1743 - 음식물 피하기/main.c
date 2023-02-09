/*
https://www.acmicpc.net/problem/
*/

#include <stdio.h>



int N, M, K;
int arr[110][110];
int visited[110][110];


int dfs(int row, int col){
    if(row<0 || row>=N) return 0;
    if(col<0 || row>=M) return 0;
    if(arr[row][col] == 0)  return 0;
    if(visited[row][col])   return 0;
    else                    visited[row][col] = 1;

    int ret = 1;

    ret += dfs(row-1    ,col);
    ret += dfs(row+1    ,col);
    ret += dfs(row  ,col-1);
    ret += dfs(row  ,col+1);

    return ret;
}


int getMax(void){
    int max = 0;
    int temp;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            temp = dfs(i,j);
            if(temp > max)  max = temp;
        }
    }

    return max;
}



void init(void){
    for(int i=0;i<110;i++){
        for(int j=0;j<110;j++){
            arr[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}


int main(void){
    scanf("%d %d %d", &N, &M, &K);
    init();

    int r,c;
    for(int i=0;i<K;i++){
        scanf("%d %d", &r, &c);
        arr[r-1][c-1] = 1;
    }

    printf("%d",getMax());
    return 0;
}