#include <iostream>
#include <vector>


std::string A,B;
std::vector<std::vector<int>> dp;

int max(int a, int b){
    return a>b?a:b;
}


int DPprocess(int a, int b){
    //fprintf(stderr, "DP : %d,%d\n", a, b);
    if(dp[a][b] != -1)  
        return dp[a][b];

    if(a==0 || b==0){
        dp[a][b] = 0;
        return 0;
    }

    if(A[a-1] == B[b-1]){
        dp[a][b] = DPprocess(a-1, b-1) + 1;
        return dp[a][b];
    }else{
        dp[a][b] = max(DPprocess(a-1, b), DPprocess(a, b-1));
        return dp[a][b];
    }

    return -1;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);


    std::cin >> A >> B;
    dp.resize(A.size()+1);

    
    for(int i=0;i<dp.size();i++){
        dp[i].resize(B.size()+1, -1);
    }

    DPprocess(A.size(), B.size());
    std::cout << dp[A.size()][B.size()];
    
    return 0;
}