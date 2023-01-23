/*
https://www.acmicpc.net/problem/1572
*/

#include <stdio.h>


int main(void){
    int N,K;
    scanf("%d %d", &N, &K);
    unsigned long long sum = 0;
    for(int i=0;i<N;i++){
        int temp;
        scanf("%d", &temp);

        if(i < K-1){
            sum += temp * (i+1);
        }else if(N-i < K){
            sum += temp * (N-i);
        }else{
            sum += temp * K;
        }
    }

    printf("%lld", sum);
    return 0;
}