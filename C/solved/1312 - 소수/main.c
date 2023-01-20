/*
https://www.acmicpc.net/problem/1312 - 소수
*/

#include <stdio.h>


int main(void){
    int A,B,N;
    scanf("%d %d %d", &A, &B, &N);

    A %= B;
    for(int i=0;i<N-1;i++){
        A*=10;
        A%=B;
    }
    A *= 10;
    printf("%d",A/B);
    return 0;
}