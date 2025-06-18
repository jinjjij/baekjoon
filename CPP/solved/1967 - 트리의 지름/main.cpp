#include <iostream>
#include <vector>
#include <queue>


int N = 0;
std::vector<std::vector<std::pair<int, int>>> adj;



int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    
    std::cin >> N;
    adj.resize(N+1);

    int f,t,c;
    for(int i=0;i<N-1;i++){
        std::cin >> f >> t >> c;
        adj[f].push_back({c,t});
        adj[t].push_back({c,f});
    }

    std::queue<std::pair<int, int>> q;
    std::vector<bool> vis(N+1, false);

    
    int maxNode = 0;
    int maxDist = 0;
    q.push({0,1});
    while(!q.empty()){
        std::pair<int, int> cur = q.front(); q.pop();
        vis[cur.second] = true;

        for(std::pair<int,int> next : adj[cur.second]){
            if(vis[next.second])    continue;
            int newDist = cur.first + next.first;

            if(maxDist < newDist){
                maxDist = newDist;
                maxNode = next.second;
            }

            q.push({newDist, next.second});
        }
    }
    
    q.push({0,maxNode});
    maxNode = 0;
    maxNode = 0;
    vis.assign(N+1, false);
    while(!q.empty()){
        std::pair<int, int> cur = q.front(); q.pop();
        vis[cur.second] = true;

        for(std::pair<int,int> next : adj[cur.second]){
            if(vis[next.second])    continue;
            int newDist = cur.first + next.first;

            if(maxDist < newDist){
                maxDist = newDist;
                maxNode = next.second;
            }

            q.push({newDist, next.second});
        }
    }

    std::cout << maxDist;
    
    return 0;
}