#include <iostream>
#include <vector>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    int count = 0;
    while(true){
        count += N;
        if(N<M)    break;
        N /= M;
    }

    std::cout << count;

    return 0;
}