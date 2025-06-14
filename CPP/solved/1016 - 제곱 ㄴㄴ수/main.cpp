#include <iostream>
#include <vector>

typedef long long lld;


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    lld min, max;
    std::cin >> min >> max;
    std::vector<bool> shieve(1000001, true);
    std::vector<bool> output(max - min + 1, true);


    for(lld i=2;i*i<=max;i++){
        if(!shieve[i])  continue;
        lld tmp = i*2;
        while(tmp <= 1000000){
            shieve[tmp] = false;
            tmp += i;
        }

        lld square = i * i;
        // j는 square로 나누어떨어지는 수들 중 가장 작은 min 이상 수
        lld start = ((min + square - 1) / square) * square;

        for (lld j = start; j <= max; j += square) {
            output[j - min] = false;
        }
    }

    int count = 0;
    for(lld i=min;i<=max;i++){
        if(output[i-min])   count++;
    }

    std::cout << count;
    
    return 0;
}