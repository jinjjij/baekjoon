#include <iostream>
#include <unordered_map>


typedef long long lld;
std::unordered_map<lld, lld> dp;
lld N,P,Q,X,Y;


lld process(lld cur){
    if(cur < 0)    return 1;
    if(dp.find(cur) != dp.end()){
        return dp[cur];
    }

    dp[cur] = process(cur/P-X) + process(cur/Q-Y);
    return dp[cur];
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    std::cin >> N >> P >> Q >> X >> Y;

    dp[0] = 1;
    std::cout << process(N);

    return 0;
}