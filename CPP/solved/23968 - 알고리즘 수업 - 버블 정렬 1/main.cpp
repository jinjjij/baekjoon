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
        std::cin >> arr[i];
    }

    int swapCount = 0;
    int endFlg = -1;
    for(int last = N-1; last > 0; last--){
        for(int i=0; i< last; i++){
            if(arr[i] > arr[i+1]){
                // swap
                int tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                swapCount ++;

                if(swapCount == K){
                    std::cout << arr[i] << " " << arr[i+1];
                    endFlg = 1;
                    break;
                }
            }
        }
        if(endFlg == 1) break;
    }

    if(endFlg == -1){
        std::cout << endFlg;
    }
    
    return 0;
}