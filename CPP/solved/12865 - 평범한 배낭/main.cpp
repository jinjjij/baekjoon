#include <iostream>
#include <vector>

int dp[101][100001] = {0};

int max(int a, int b){
    return a>b?a:b;
}


typedef struct item{
    int w, v;
} item;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, k;

    std::cin >> n >> k; 
    std::vector<item> bag;

    

    int w,v;
    for(int i=0;i<n;i++){
        std::cin >> w >> v;
        bag.push_back({w,v});
    }


    for(int i=0;i<n;i++){
        for(int w=0;w<=k;w++){
            if(w >= bag[i].w){
                if(i==0){
                    dp[i][w] = bag[i].v;
                }else{
                    dp[i][w] = max(dp[i-1][w], dp[i-1][w-bag[i].w] + bag[i].v);
                }
            }else{           
                if(i==0){
                    dp[i][w] = 0;
                }else{
                    dp[i][w] = dp[i-1][w];
                }
            }
        }
    }


    std::cout << dp[n-1][k];
    
    return 0;
}