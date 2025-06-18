#include <iostream>
#include <vector>
#include <queue>


std::vector<int> djkstra(int V, int startV, const std::vector<std::vector<std::pair<int, int>>>& adj){
    
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    std::vector<int> dist(V+1, INT32_MAX);
    dist[startV] = 0;

    pq.push({0,startV});

    std::pair<int, int> cur;
    while(!pq.empty()){
        cur = pq.top(); pq.pop();

        if (cur.first > dist[cur.second]) continue;
        
        for(std::pair<int, int> next : adj[cur.second]){
            if(dist[next.second] > cur.first + next.first){
                dist[next.second] = cur.first + next.first;
                pq.push({dist[next.second], next.second});
            }
        }
    }

    return dist;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n,m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int,int>>> adj(n+1);

    int f,t,c;
    for(int i=0;i<m;i++){
        std::cin >> f >> t >> c;
        adj[f].push_back({c,t});
    }

    std::vector<int> dist;

    for(int i=1;i<=n;i++){
        dist = djkstra(n, i, adj);
        for(int j=1;j<=n;j++){
            if(dist[j] == INT32_MAX){
                std::cout << "0 ";
            }else{
                std::cout << dist[j] << " ";
            } 
        }
        std::cout << "\n";
    }

    
    
    return 0;
}