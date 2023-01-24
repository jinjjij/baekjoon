/*
https://www.acmicpc.net/problem/
*/

#include <stdio.h>
typedef long long ll;


ll ModExponent(ll n, int power, int mod){
    
    if(power == 0){
        return 1;
    }

    ll half = ModExponent(n, power/2, mod);
    ll result = (half * half) % mod;

    result = (power%2)? (result * n)%mod : result;

    //printf("ModExponent : %lld\n", result);
    return result;
}


ll RNG(ll m, ll a, ll c, ll x0, ll n, ll g){
    if(a == 0){
        return c%m%g;
    }

    if(m < 2)   return 0;

    ll ret = 0;
    ll a_pow_n = ModExponent(a, n, m);
    ll a_rev = ModExponent(a-1, m-2, m);
    ll arg1 = (a_pow_n * x0)%m;
    ll arg2 = ((a_pow_n - 1) * a_rev)%m;
    arg2 = arg2 * c % m;

    ret = (arg1 + arg2)%m;
    ret %= g;
    return ret;
}


int main(void){
    ll m,a,c,x0,n,g;
    scanf("%lld %lld %lld %lld %lld %lld", &m, &a, &c, &x0, &n, &g);
    printf("%lld", RNG(m,a,c,x0,n,g));
    return 0;
}