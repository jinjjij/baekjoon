/*
https://www.acmicpc.net/problem/1328
*/

#include <stdio.h>
#define P 1000000007

typedef unsigned long long ll;


ll ar[100][100];


ll ModFact(ll n){
    
    ll result = 1;
    
    for(int i=2;i<=n;i++){
        result *= i;
        result %= P;
    }

    //printf("ModFact : %lld\n", result);
    return result;
}


ll ModExponent(ll n, int power){
    
    if(power == 0){
        return 1;
    }

    ll half = ModExponent(n, power/2);
    ll result = (half * half) % P;

    result = (power%2)? (result * n)%P : result;

    //printf("ModExponent : %lld\n", result);
    return result;
}


ll Permutation(int n, int k){
    ll N_fac = ModFact(n);
    ll NK_fac = ModFact(n-k);

    NK_fac = ModExponent(NK_fac, P-2);
    
    return (N_fac * NK_fac) % P;
}


ll Combination(int n, int k){
    ll N_fac = ModFact(n);
    ll NK_fac = ModFact(n-k);
    ll K_fac = ModFact(k);

    NK_fac = ModExponent(NK_fac, P-2);
    K_fac = ModExponent(K_fac, P-2);

    ll result = (N_fac * NK_fac) % P;
    result *= K_fac;
    result %= P;

    return result;
}



void init(void){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(i==j){
                ar[i][j] = 1;
            }else{
                ar[i][j] = -1;
            }
            
        }
    }
}



ll dp(int N, int K){
    
    ll ret = 0;

    if(N<K){
        ret = -1;  //  err
    }
    else if(N==K){
        ret = 1;
    }  
    else if(ar[N][K] != -1){
        ret = ar[N][K];
    }
    else if(K==0){
        ret = 0;
    }
    else if(K == 1){
        ret = ModFact(N-1) % P;
    }else{
        for(int i=0;i<=N-K;i++){
            ret += Permutation(N-1, i) * dp(N-1-i, K-1);
            ret %= P;
        }
    }
    

    ret %= P;
    ar[N][K] = ret;
    //fprintf(stderr,"dp(%d, %d)", N, K);
    //fprintf(stderr," = %lld\n", ret);
    return ret;
}


int main(void){
    int N,L,R;
    init();
    scanf("%d %d %d", &N, &L, &R);

    ll ret = 0;
    if(L==1 && R>1){
        ret = dp(N-1, R-1);
    }else if(R==1 && L>1){
        ret = dp(N-1, L-1);
    }else if(L==1 && R==1){
        if(N==1){
            ret = 1;
        }else{
            ret = 0;
        }
    }else{
        for(int i=0;i<=N-L-R+1;i++){
            //fprintf(stderr,"i = %d -> ", i);
            //fprintf(stderr,"C(%d,%d) * dp(%d,%d) * dp(%d,%d)\n",N-1, L-1+i, L-1+i,L-1, N-L-i,R-1);
            ll temp = (dp(L-1+i,L-1) * dp(N-L-i,R-1)) % P;
            temp = (temp * Combination(N-1, L-1+i)) % P;
            ret += temp;
            ret %= P;
            //fprintf(stderr,"ret : %d\n", temp);
        }
    }

    printf("%llu", ret%P);

    return 0;
}