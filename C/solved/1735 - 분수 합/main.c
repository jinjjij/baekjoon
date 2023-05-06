/*
https://www.acmicpc.net/problem/1735
*/


#include <stdio.h>
typedef long long int lld;


// return gcd
lld Euclid(lld N, lld M){
    if(N<1 || M<1){
        return -1;
    }

    if(N==1 || M == 1){
        return 1;
    }

    if(N<M){
        int tmp = M;
        M = N;
        N = tmp;
    }

    if(N%M == 0){
        return M;
    }else{
        return Euclid(M, N%M);
    }
}



int main(void){
    lld A,B,C,D;
    lld up,down;

    scanf("%d %d", &B, &A);
    scanf("%d %d", &D, &C);

    down = A*C;
    up = B*C + A*D;

    lld gcd = Euclid(down, up);

    down /= gcd;
    up /= gcd;

    printf("%lld %lld", up, down);

    return 0;
}