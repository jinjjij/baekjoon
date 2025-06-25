#include <iostream>
#include <vector>


std::vector<int> A,B;


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::cin >> N;
    A.resize(N);
    for(int i=0;i<N;i++){
        std::cin >> A[i];
    }

    std::cin >> M;
    B.resize(M);
    for(int i=0;i<N;i++){
        std::cin >> B[i];
    }


    


    return 0;
}