/*
https://www.acmicpc.net/problem/2903
*/

#include <stdio.h>
#include <math.h>

// 3 -> 5 -> 9 -> 17 -> (2^N+1)^2 = 2^2N + 2^N+1 + 1

typedef long long int lld;

int main(void){
    lld out = 2;
    int N = 0;
    scanf("%d", &N);
    for(int i=0;i<N-1;i++){
        out *= 2;
    }
    out += 1;

    out = out*out;

    printf("%lld", out);
    return 0;
}