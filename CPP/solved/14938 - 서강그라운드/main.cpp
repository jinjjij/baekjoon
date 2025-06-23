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


std::vector<int> item;
std::vector<std::vector<std::pair<int, int>>> adj;
std::vector<int> result;


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, m, r;
    std::cin >> n >> m >> r;

    item.resize(n+1, 0);
    result.resize(n+1, 0);
    adj.resize(n+1);

    for(int i=1;i<=n;i++){
        std::cin >> item[i];
    }

    

    int from, to, cost;
    for(int i=0;i<r;i++){
        std::cin >> from >> to >> cost;
        adj[from].push_back({cost, to});
        adj[to].push_back({cost, from});
    }


    int max = 0;
    
    for(int i=1;i<=n;i++){
        std::vector<int> minDist = djkstra(n, i, adj);
        int count = 0;
        for(int j=1;j<=n;j++){
            if(minDist[j] <= m){
                count += item[j];
            }
        }
        if(max < count) max = count;
    }
    
    
    std::cout << max;
    
    return 0;
}