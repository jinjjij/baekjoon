/*
https://www.acmicpc.net/problem/14500
*/

#include <stdio.h>

int N,M;
int arr[500][500];
int visited[500][500];


int inbound(int x, int y){
    if(0<=x && x <= N && 0<=y && y<=M){
        return 1;
    }else{
        return 0;
    }
}


int dfs(int x, int y){
    if(inbound(x,y)==0) return -1;
    int this = arr[x][y];
    int max = 0;
    int temp = 0;

    // OOOO -> 2개
    if(inbound(x,y+3)){
        temp = arr[x][y] + arr[x][y+1] + arr[x][y+2] + arr[x][y+3];
    }
    if(temp>max)    max = temp;

    if(inbound(x+3,y)){
        temp = arr[x][y] + arr[x+1][y] + arr[x+2][y] + arr[x+3][y];
    }
    if(temp>max)    max = temp;

    //  OO
    //  OO  -> 1개
    if(inbound(x+1,y+1)){
        temp = arr[x][y] + arr[x+1][y] + arr[x][y+1] + arr[x+1][y+1];
    }
    if(temp>max)    max = temp;

    //  O
    //  OOO -> 4개

    if(inbound(x-2,y) && inbound(x,y+1)){
        temp = arr[x-2][y] + arr[x-1][y] + arr[x][y] + arr[x][y+1];
    }
    if(temp>max)    max = temp;

    if(inbound(x+1,y) && inbound(x,y+2)){
        temp = arr[x+1][y] + arr[x][y] + arr[x][y+1] + arr[x][y+2];
    }
    if(temp>max)    max = temp;

    if(inbound(x+2,y) && inbound(x,y-1)){
        temp = arr[x+2][y] + arr[x+1][y] + arr[x][y] + arr[x][y-1];
    }
    if(temp>max)    max = temp;

    if(inbound(x-1,y) && inbound(x,y-2)){
        temp = arr[x-1][y] + arr[x][y] + arr[x][y-1] + arr[x][y-2];
    }
    if(temp>max)    max = temp;

    //   O
    //  OOO -> 4개
    if(inbound(x-1,y) && inbound(x,y+1) && inbound(x,y-1)){
        temp = arr[x-1][y] + arr[x][y+1] + arr[x][y-1] + arr[x][y];
    }
    if(temp>max)    max = temp;

    if(inbound(x-1,y) && inbound(x+1,y) && inbound(x,y+1)){
        temp = arr[x-1][y] + arr[x+1][y] + arr[x][y+1] + arr[x][y];
    }
    if(temp>max)    max = temp;

    if(inbound(x,y-1) && inbound(x,y+1) && inbound(x+1,y)){
        temp = arr[x][y-1] + arr[x][y+1] + arr[x+1][y] + arr[x][y];
    }
    if(temp>max)    max = temp;

    if(inbound(x-1,y) && inbound(x+1,y) && inbound(x,y-1)){
        temp = arr[x-1][y] + arr[x+1][y] + arr[x][y-1] + arr[x][y];
    }
    if(temp>max)    max = temp;

    //   OO
    //  OO  -> 2개
    if(inbound(x-1,y) && inbound(x+1,y+1)){
        temp = arr[x][y] + arr[x-1][y] + arr[x][y+1] + arr[x+1][y+1];
    }
    if(temp>max)    max = temp;

    if(inbound(x+1,y-1) && inbound(x,y+1)){
        temp = arr[x][y] + arr[x+1][y] + arr[x+1][y-1] + arr[x][y+1];
    }
    if(temp>max)    max = temp;


    visited[x][y] = 1;
    return max;
}


int main(void){
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d", &arr[i][j]);
            visited[i][j] = 0;
        }
    }

    int max = 0;
    int temp = 0;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            temp = dfs(i,j);
            if(temp > max)  max = temp;
        }
    }

    printf("%d", max);
    return 0;
}