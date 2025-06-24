#include <iostream>
#include <vector>


int max(int a, int b){
    return a>b?a:b;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    int input;
    int M = 0;
    for(int i=N;i>0;i--){
        std::cin >> input;
        M = max(M, input-i);
    }

    std::cout << M;
    return 0;
}