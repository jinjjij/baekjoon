#include <iostream>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    long long N, M;
    std::cin >> N >> M;

    std::cout << N*M/2;
    return 0;
}