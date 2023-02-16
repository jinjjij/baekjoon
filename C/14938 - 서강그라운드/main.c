/*
https://www.acmicpc.net/problem/14938
*/

#include <stdio.h>

int graph[100][100];
int value[100];
int visited[100];


void init(void){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            graph[i][j] = -1;
        }
        value[i] = 0;
        visited[i] = 0;
    }
}





int getmax(int N, int M){

}


int main(void){
    int N,M,R,t,a,b,l;
    scanf("%d %d %d", &N, &M, &R);
    for(int i=0;i<N;i++)    scanf("%d", &value[i]);
    for(int i=0;i<R;i++){
        scanf("%d %d %d", &a, &b, &l);
        graph[a-1][b-1] = l;
        graph[b-1][a-1] = l;
    }

    printf("%d", getmax(N,M));

    return 0;
}