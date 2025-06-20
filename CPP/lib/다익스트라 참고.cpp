/*
    원본 : 최소비용 구하기
    https://www.acmicpc.net/problem/1916
*/
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