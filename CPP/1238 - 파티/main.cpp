#include <iostream>
#include <vector>
#include <queue>



int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N,M,X;
    std::cin >> N >> M >> X;

    std::vector<std::vector<std::pair<int, int>>> graph(M);
    std::vector<std::vector<std::pair<int, int>>> graph_rev(M);

    std::vector<int> dist(N+1, INT32_MAX);
    std::vector<int> dist_rev(N+1, INT32_MAX);

    std::priority_queue<std::pair<int, int>> pq;
    std::priority_queue<std::pair<int, int>> pq_rev;

    int a,b,c;
    for(int i=0;i<M;i++){
        std::cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph_rev[b].push_back({a,c});
    }


    // 정방향 다익스트라 : 출발점 X

    pq.push({0, X});

    while(!pq.empty()){
        int to = pq.top().first;
        int cost = pq.top().second;
        pq.pop();


        if(dist[to] < cost) continue;

        for(auto next : graph[to]){
            if(next.second + cost < dist[next.first])
        }
        
    }



    // 역방향 다익스트라 : 출발점 X


    return 0;
}