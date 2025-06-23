#include <iostream>
#include <vector>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T;
    
    std::vector<bool> isPrime(1000001, true);

    isPrime[1] = false;

    for(int i=2;i<=1000;i++){
        if(!isPrime[i]) continue;
        for(int j=i*i;j<=1000000;j+=i){
            isPrime[j] = false;
        }
    }

    std::vector<int> goldbach(1000001, 0);
    std::vector<int> primes;
    primes.reserve(80000);
    for (int i = 2; i <= 1000000; ++i) {
        if (isPrime[i]) primes.push_back(i);
    }
    
    for (int i = 0; i < primes.size(); ++i) {
        for (int j = i; j < primes.size(); ++j) {
            int sum = primes[i] + primes[j];
            if (sum > 1000000) break;  // 반드시 필요
            goldbach[sum]++;
        }
    }
    
    
    std::cin >> T;
    int input = 0;
    for(int t=0;t<T;t++){
        std::cin >> input;
        std::cout << goldbach[input] << "\n";
    }
    
    
    return 0;
}