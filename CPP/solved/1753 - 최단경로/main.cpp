#include <iostream>
#include <vector>
#include <queue>


typedef std::pair<int, int> coord;


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int V,E,K;
    std::cin >> V >> E >> K;

    std::vector<std::vector<coord>> adj(V+1);
    int f,t,c;
    for(int i=0;i<E;i++){
        std::cin >> f >> t >> c;
        adj[f].push_back({c,t});
    }


    std::priority_queue<coord, std::vector<coord>, std::greater<coord>> pq;
    std::vector<int> dist(V+1, INT32_MAX);
    dist[K] = 0;

    pq.push({0,K});

    coord cur;
    while(!pq.empty()){
        cur = pq.top(); pq.pop();

        if (cur.first > dist[cur.second]) continue;
        
        for(coord next : adj[cur.second]){
            if(dist[next.second] > cur.first + next.first){
                dist[next.second] = cur.first + next.first;
                pq.push({dist[next.second], next.second});
            }
        }
    }


    for(int i=1;i<V+1;i++){
        if(dist[i] == INT32_MAX){
            std::cout << "INF\n";
        }else{
            std::cout << dist[i] << "\n";
        }
    }
    
    
    return 0;
}