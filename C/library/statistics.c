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