#include <iostream>
#include <sstream>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    std::stringstream ss;

    for(int i=0;i<N;i++){
        ss << N;
    }

    std::cout << ss.str().substr(0, M);
    
    return 0;
}