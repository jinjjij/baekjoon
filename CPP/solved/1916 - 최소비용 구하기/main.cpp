#include <iostream>
#include <vector>
#include <queue>


typedef std::pair<int, int> node;


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<node>> bus(N+1);

    int f,t,c;
    for(int i=0;i<M;i++){
        std::cin >> f >> t >> c;
        bus[f].push_back({c, t});
    }

    int start, to;
    std::cin >> start >> to;

    std::priority_queue<node> pq;
    std::vector<int> dist(N+1, INT32_MAX);

    dist[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty()){
        node cur = pq.top(); pq.pop();

        if(dist[cur.second] < cur.first) continue;  // 시간 많이 줄여줌

        for(node e : bus[cur.second]){
            if(cur.first + e.first < dist[e.second]){
                dist[e.second] = cur.first + e.first;
                pq.push({cur.first + e.first, e.second});
            }
        }
    }

    std::cout << dist[to];
    
    return 0;
}