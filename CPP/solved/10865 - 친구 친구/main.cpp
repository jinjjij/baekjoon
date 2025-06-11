#include <iostream>
#include <vector>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::cin >> N >> M;
    std::vector<int> count(N+1, 0);

    int input1, input2;
    for(int i=0;i<M;i++){
        std::cin >> input1 >> input2;
        count[input1]++;
        count[input2]++;
    }
    
    for(int i=0;i<N;i++){
        std::cout << count[i+1] << "\n";
    }
    return 0;
}