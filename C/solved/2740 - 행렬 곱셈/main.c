/*
https://www.acmicpc.net/problem/2740 - 행렬 곱셈

*/


#include <stdio.h>

int main(void){
    int N,M,K;
    int A[110][110];
    int B[110][110];
    int c;

    scanf("%d %d", &N, &M);
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d", &A[i][j]);
        }
    }


    scanf("%d %d", &M, &K);
    
    for(int i=0;i<M;i++){
        for(int j=0;j<K;j++){
            scanf("%d", &B[i][j]);
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<K;j++){
            c = 0;
            for(int k=0;k<M;k++){
                c += A[i][k] * B[k][j];
            }
            printf("%d ",c);
        }
        printf("\n");
    }
    return 0;
}