#include <iostream>
#include <vector>
#include <algorithm>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 0;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N);

    int input;
    for(int i=0;i<N;i++){
        std::cin >> input;
        A[i] = {input, i};
    }

    std::sort(A.begin(), A.end());

    std::vector<int> P(N);
    for(int i=0;i<N;i++){
        P[A[i].second] = i;
    }

    for(int i=0;i<N;i++){
        std::cout << P[i] << " ";
    }




    
    return 0;
}