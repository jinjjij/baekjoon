/*
https://www.acmicpc.net/problem/11401 - 이항 계수 3

*/


#include <stdio.h>
#define P 1000000007


long long ModFact(long long n){
    
     long result = 1;
    
    for(int i=2;i<=n;i++){
        result *= i;
        result %= P;
    }

    //printf("ModFact : %lld\n", result);
    return result;
}


long long ModExponent(long long n, int power){
    
    if(power == 0){
        return 1;
    }

    long long half = ModExponent(n, power/2);
    long long result = (half * half) % P;

    result = (power%2)? (result * n)%P : result;

    //printf("ModExponent : %lld\n", result);
    return result;
}


int main(void){
    long long N, K;
    scanf("%lld %lld", &N, &K);

    long long N_fac = ModFact(N);
    long long NK_fac = ModFact(N-K);
    long long K_fac = ModFact(K);

    NK_fac = ModExponent(NK_fac, P-2);
    K_fac = ModExponent(K_fac, P-2);

    long long result = (N_fac * NK_fac) % P;
    result *= K_fac;
    result %= P;

    printf("%lld", result);
    return 0;
}