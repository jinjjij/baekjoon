#include <iostream>
#include <vector>


long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;

    base %= mod;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod; // 홀수면 곱함
        }
        base = (base * base) % mod;
        exp /= 2;
    }

    return result;
}


long long modInv(long long a, long long m){
    return mod_pow(a, m-2, m);
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    
    int M = 0;
    std::cin >> M;

    long long a, b;
    long long sum = 0;
    for(int i=0;i<M;i++){
        std::cin >> a >> b;
        sum += (b%1000000007) * modInv(a, 1000000007);
        sum %= 1000000007;
    }

    std::cout << sum;
    
    return 0;
}