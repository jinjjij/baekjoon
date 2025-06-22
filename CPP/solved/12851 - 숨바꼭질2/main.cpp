#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>


#define SIZE 100000


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::vector<int> dist(SIZE*2, -1);
    std::vector<int> count(SIZE*2, 0);

    int N, K;
    std::cin >> N >> K;

    std::queue<int> q;
    dist[N] = 0;
    count[N] = 1;
    q.push(N);

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int next : {cur - 1, cur + 1, cur * 2}) {
            if (next < 0 || next > SIZE) continue;

            if (dist[next] == -1) {
                // 처음 도달
                dist[next] = dist[cur] + 1;
                count[next] = count[cur];
                q.push(next);
            } else if (dist[next] == dist[cur] + 1) {
                // 같은 시간에 또 도달한 경우 (추가 경로)
                count[next] += count[cur];
            }
        }
    }

    std::cout << dist[K] << "\n" << count[K] << "\n";

    
    return 0;
}