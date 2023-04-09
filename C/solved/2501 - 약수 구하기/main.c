/*
https://www.acmicpc.net/problem/2501
*/

#include <stdio.h>

int main(void){
    int N, K;
    scanf("%d %d", &N, &K);
    int out = 0;

    for(int i=1;i<=N;i++){
        if(N%i==0){
            K--;
            if(K==0){
                out = i;
                break;
            }
        }
    }

    printf("%d", out);
    return 0;
}