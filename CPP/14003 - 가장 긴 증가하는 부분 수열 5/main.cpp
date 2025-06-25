#include <iostream>
#include <vector>
#include <algorithm>

typedef long long lld;


std::vector<int> LongestIncreasingSubsequence(const std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> dp(n, 1);        // dp[i] = LIS 길이
    std::vector<int> prev(n, -1);     // prev[i] = LIS 직전 원소 인덱스

    int maxLen = 0;
    int lastIndex = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }

        if(dp[i] > maxLen) {
            maxLen = dp[i];
            lastIndex = i;
        }
    }

    // 백트래킹으로 실제 LIS 구하기
    std::vector<int> lis;
    while(lastIndex != -1) {
        lis.push_back(arr[lastIndex]);
        lastIndex = prev[lastIndex];
    }

    std::reverse(lis.begin(), lis.end());
    return lis;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 0;
    std::cin >> N;

    std::vector<int> input(N);
    for(int i=0;i<N;i++){
        std::cin >> input[i];
    }

    std::vector<int> lis = LongestIncreasingSubsequence(input);
    std::cout << lis.size() << "\n";
    for(int i : lis){
        std::cout << i << " ";
    }

    return 0;
}