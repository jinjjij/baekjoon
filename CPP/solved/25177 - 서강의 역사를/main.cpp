#include <iostream>
#include <vector>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N,M;
    std::cin >> N >> M;

    std::vector<int> offset(N>M?N:M, 0);

    int input;
    for(int i=0;i<N;i++){
        std::cin >> input;
        offset[i] = -input;
    }

    int max = 0;
    for(int i=0;i<M;i++){
        std::cin >> input;
        offset[i] += input;

        if(max < offset[i]){
            max = offset[i];
        }
    }

    std::cout << max;
    
    return 0;
}