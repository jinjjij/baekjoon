/*
https://www.acmicpc.net/problem/1629 - 곱셈
*/

#include <stdio.h>


long long modSq(long long A, long long pow, long long mod){
    A %= mod;
    if(pow == 0)    return 1;
    long long half = modSq(A, pow/2, mod);

    long long ret = half * half;
    ret %= mod;

    if(pow%2){
        ret *= A;
    }
    ret %= mod;

    return ret;
}


int main(void){
    long long A,B,C;
    scanf("%lld %lld %lld", &A, &B, &C);
    printf("%d", modSq(A,B,C));

    return 0;
}