#include <iostream>
#include <vector>
#include <queue>

typedef long long lld;


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


lld min(lld a, lld b){
    return a<b?a:b;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N,M;
    std::cin >> N >> M;

    std::vector<std::vector<std::pair<int, int>>> adj(N+1);

    int f, t, c;
    for(int i=0;i<M;i++){
        std::cin >> f >> t >> c;

        adj[f].push_back({c,t});
        adj[t].push_back({c,f});
    }

    int u,v;
    std::cin >> u >> v;

    std::vector<int> djOut[3];

    djOut[0] = djkstra(N,1,adj);
    djOut[1] = djkstra(N,u,adj);
    djOut[2] = djkstra(N,v,adj);

    lld result = 0;
    
    result = min((lld)djOut[0][u] + (lld)djOut[1][v] + (lld)djOut[2][N], (lld)djOut[0][v] + (lld)djOut[2][u] + (lld)djOut[1][N]);

    if(result >= INT32_MAX){
        std::cout << "-1";
    }else{
        std::cout << result;
    }
    
    return 0;
}