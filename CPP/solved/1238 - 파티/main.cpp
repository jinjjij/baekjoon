#include <iostream>
#include <vector>
#include <queue>



int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N,M,X;
    std::cin >> N >> M >> X;

    std::vector<std::vector<std::pair<int, int>>> graph(N+1);
    std::vector<std::vector<std::pair<int, int>>> graph_rev(N+1);

    std::vector<int> dist(N+1, INT32_MAX);
    std::vector<int> dist_rev(N+1, INT32_MAX);

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq_rev;

    int a,b,c;
    for(int i=0;i<M;i++){
        std::cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph_rev[b].push_back({a,c});
    }


    // 정방향 다익스트라 : 출발점 X

    pq.push({0, X});
    dist[X] = 0;

    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();


        if(dist[cur] < cost) continue;

        for(auto& next : graph[cur]){
            if(dist[next.first] > next.second + cost){
                dist[next.first] = cost + next.second;
                pq.push({dist[next.first], next.first});
            }
        }
    }


    // 역방향 다익스트라 : 출발점 X

    pq_rev.push({0, X});
    dist_rev[X] = 0;

    while(!pq_rev.empty()){
        int cost = pq_rev.top().first;
        int cur = pq_rev.top().second;
        pq_rev.pop();


        if(dist_rev[cur] < cost) continue;

        for(auto& next : graph_rev[cur]){
            if(dist_rev[next.first] > next.second + cost){
                dist_rev[next.first] = cost + next.second;
                pq_rev.push({dist_rev[next.first], next.first});
            }
        }
    }


    // 왕복시간 최댓값 계산
    int max = 0;
    int tmp = 0;
    for(int i=1;i<=N;i++){
        tmp = dist[i] + dist_rev[i];
        if(max < tmp){
            max = tmp;
        }
    }

    std::cout << max;

    return 0;
}