/*
https://www.acmicpc.net/problem/
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
    lld A, B;
    scanf("%lld %lld", &A, &B);

    lld gcd = Euclid(A,B);
    //printf("gcd : %lld\n", gcd);
    lld Atemp = A/gcd;
    //printf("Atemp : %lld\n", Atemp);
    lld lcm = B * Atemp;
    //printf("lcm : %lld\n", lcm);

    printf("%lld", lcm);
    return 0;
}