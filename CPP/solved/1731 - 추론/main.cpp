#include <iostream>
#include <vector>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 0;
    std::cin >> N;
    std::vector<int> input(N);

    for(int i=0;i<N;i++){
        std::cin >> input[i];
    }

    long long mid = input[0];
    mid += input[2];
    mid /= 2;

    if(mid == input[1]){    // 등차
        int d = input[1] - input[0];
        std::cout << input[N-1] + d;
    }else{  // 등비
        std::cout << input[N-1] * (input[1]/input[0]);
    }
    
    return 0;
}