#include <iostream>
#include <vector>
#include <queue>


struct Order{
    int from, to;
};


int max(int a, int b){
    return a>b?a:b;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T;
    std::cin >> T;

    for(int t=0;t<T;t++){
        int N, K;
        std::cin >> N >> K;
        
        std::vector<int> cost(N+1);
        std::vector<std::vector<int>> graph(N+1);
        std::vector<int> dp(N+1, 0);
        std::vector<int> indegree(N+1, 0);
        std::queue<int> q;

        
        int input;
        for(int n=1;n<N+1;n++){
            std::cin >> cost[n];
        }


        int a,b;
        for(int k=0;k<K;k++){
            std::cin >> a >> b;
            graph[a].push_back(b);
            indegree[b] ++;
        }

        
        for(int i=1;i<N+1;i++){
            if(indegree[i] == 0){
                q.push(i);
                dp[i] = cost[i];
            }
        }

        int cur;
        while(!q.empty()){
            cur = q.front();
            q.pop();

            for(int next : graph[cur]){
                indegree[next] --;
                dp[next] = max(dp[next], dp[cur] + cost[next]);
                if(indegree[next] == 0){
                    q.push(next);
                }
            }
        }

        int W;
        std::cin >> W;
        std::cout << dp[W] << "\n";
    }
    
    return 0;
}