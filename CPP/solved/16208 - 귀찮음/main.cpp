#include <iostream>
#include <vector>
#include <algorithm>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 0;
    std::cin >> N;

    std::vector<int> arr(N);
    std::vector<int> sum(N);
    for(int i=0;i<N;i++){
        std::cin >> arr[i];
    }

    std::sort(arr.begin(), arr.end());

    sum[N-1] = arr[N-1];
    for(int i=N-2;i>=0;i--){
        sum[i] = sum[i+1] + arr[i];
    }

    long long cost = 0;
    for(int i=0;i<N-1;i++){
        cost += arr[i] * sum[i+1];
    }

    std::cout << cost;
    
    return 0;
}