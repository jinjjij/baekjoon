#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


std::vector<int> djkstra(int V, int startV, const std::vector<std::vector<std::pair<int, int>>>& adj, std::vector<int>& path, int endV){
    std::vector<int> prev(V+1, -1);
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
                prev[next.second] = cur.second;
                pq.push({dist[next.second], next.second});
            }
        }
    }

    for(int v = endV; v != -1; v = prev[v]){
        path.push_back(v);
    }
    std::reverse(path.begin(), path.end());

    return dist;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<std::pair<int, int>>> adj(N+1);
    int from, to, cost;
    for(int i=0;i<M;i++){
        std::cin >> from >> to >> cost;
        adj[from].push_back({cost, to});
    }

    int start, end;
    std::cin >> start >> end;

    std::vector<int> path;
    std::vector<int> dist = djkstra(N, start, adj, path, end);
    

    std::cout << dist[end] << "\n";
    std::cout << path.size() << "\n";
    for(int i : path){
        std::cout << i << " ";
    }

    return 0;
}