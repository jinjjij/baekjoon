#include <iostream>
#include <vector>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, K;
    std::cin >> N >> K;

    std::vector<int> arr(N);
    for(int i=0;i<N;i++){
        arr[i] = i+1;
    }
    
    int curIndex = 0;
    
    std::cout << "<";
    for(int i=0;i<N;i++){
        curIndex += K-1;
        curIndex %= arr.size();

        std::cout << arr[curIndex];
        if(i!=N-1)  std::cout << ", ";
        arr.erase(arr.begin() + curIndex);
    }
    std::cout << ">";

    return 0;
}