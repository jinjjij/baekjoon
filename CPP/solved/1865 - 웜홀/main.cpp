#include <iostream>
#include <vector>


/*
    V : 정점점의 개수
    start : 시작할 노드
    edges : 간선 정보
    return : 음수 루프가 있다면 true
*/

struct Edge {
    int from, to, weight;
};

bool bellmanFord(int V, int start, std::vector<Edge>& edges){
    std::vector<int> dist;
    dist.assign(V, INT32_MAX);
    dist[start] = 0;

    for(int i=0;i<V;i++){
        for(auto& e : edges){
            if(dist[e.from] != INT32_MAX && dist[e.to] > dist[e.from] + e.weight){
                dist[e.to] = dist[e.from] + e.weight;
            }
        }
    }


    for(auto& e : edges){
        if(dist[e.from] != INT32_MAX && dist[e.to] > dist[e.from] + e.weight){
            return true;
        }
    }
    return false;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T, N, M, W;
    std::cin >> T;

    for(int t=0;t<T;t++){
        std::vector<Edge> edges;
        std::cin >> N >> M >> W;
        
        int S,E,T;
        // 도로
        for(int i=0;i<M;i++){
            std::cin >> S >> E >> T;
            edges.push_back({S,E,T});
            edges.push_back({E,S,T});
        }

        // 웜홀
        for(int i=0;i<W;i++){
            std::cin >> S >> E >> T;
            edges.push_back({S,E,-T});
        }


        // 가상의 비용 0 노드를 추가해서 벨만포드를 한번만 돌릴 수 있게 
        for(int i=0;i<N;i++){
            edges.push_back({0, i+1, 0});
        }

        // 벨만 - 포드
        if(bellmanFord(N+1, 0, edges)){
            std::cout << "YES\n";
        }else{
            std::cout << "NO\n";
        }
    }

    return 0;
}





