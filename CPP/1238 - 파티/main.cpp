#include <iostream>


#define SIZE 1001
#define INF 100000000

int adj[SIZE][SIZE];
int min_len_f[SIZE];
int min_len_b[SIZE];
bool vis[SIZE];




void init(void){
    for(int i=0;i<SIZE;i++){
        min_len_f[i] = INF;
        min_len_b[i] = INF;
        for(int j=0;j<SIZE;j++){
            adj[i][j] = INF;
        }
    }
}


int getMinIndex(int size, int origin){
    int min = INF;
    int ret = 1;
    for(int i=1;i<=size;i++){
        if(adj[origin][i] < min && !vis[i]){
            min = adj[origin][i];
            ret = i;
        }
    }

    return ret;
}



void dijkstra(int size, int origin){
    

    
}



int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M, X;
    std::cin >> N;
    std::cin >> M;
    std::cin >> X;

    init();

    int from, to, dist;
    for(int i=0;i<M;i++){
        std::cin >> from;
        std::cin >> to;
        std::cin >> dist;

        adj[from][to] = dist;
    }

    for(int i=1;i<=N;i++){
        adj[i][i] = 0;
    }

    // dijkstra_front
    for(int i=1;i<=N;i++){
        vis[i] = false;
        min_len_f[i] = adj[X][i];
    }
    vis[X] = true;

    int cur;
    for(int i=0;i<N-2;i++){
        cur = getMinIndex(N, X);
        vis[cur] = true;
        for(int j=1; j<=N; j++ ){
            if(!vis[j] && min_len_f[cur] + adj[cur][j] < min_len_f[j]){
                min_len_f[j] = min_len_f[cur] + adj[cur][j];
            }
        }
    }

    // dijkstra_back
    for(int i=1;i<=N;i++){
        vis[i] = false;
        min_len_b[i] = adj[X][i];
    }
    vis[X] = true;

    for(int i=0;i<N-2;i++){
        cur = getMinIndex(N, X);
        vis[cur] = true;
        for(int j=1; j<=N; j++ ){
            if(!vis[j] && min_len_b[cur] + adj[cur][j] < min_len_b[j]){
                min_len_b[j] = min_len_b[cur] + adj[cur][j];
            }
        }
    }






    int ret = 0;


    for(int i=1;i<=N;i++){
        int len = min_len_b[i] + min_len_f[i];
        if(len >= INF){
            continue;
        }else{
            ret = ret<len?len:ret;
        }
    }


    std::cout << ret << "\n";

    return 0;
}