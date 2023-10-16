#include <iostream>
#include <vector>
#include <utility>


int max(int a, int b){
    return a>b?a:b;
}


typedef struct _edge{
    int to;
    int dist;
} edge;


typedef struct edge_from_node{
    int size;
    std::vector<edge> arr;
} efn;


efn* edges;
int fardest_node;
int max_dist;
bool *vis;


void initDfs(int root, int nodeSize){
    fardest_node = root;
    max_dist = 0;
    for(int i=0;i<=nodeSize;i++){
        vis[i] = false;
    }
    vis[root] = true;
}


void dfs(int node, int dist){
    
    if(max_dist < dist){
        fardest_node = node;
        max_dist = dist;
    }

    int size = edges[node].size;
    for(int i=0;i<size;i++){
        int next_node = edges[node].arr[i].to;
        
        if(vis[next_node] == false){
            vis[next_node] = true;
            dfs(next_node , edges[node].arr[i].dist + dist);
            vis[next_node] = false;
        }
        
    }
    
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int V;
    std::cin >> V;
    
    edges = new efn[V+1];
    vis = new bool[V+1];
    
    int node, node_next, dist;
    for(int i=0;i<V;i++){
        std::cin >> node;
        int count = 0;
        
        
        while(true){
            std::cin >> node_next;
            if(node_next == -1){
                break;
            }else{
                std::cin >> dist;
            }
            edge newedge;
            newedge.dist = dist;
            newedge.to = node_next;

            edges[node].arr.push_back(newedge);
            count ++;
        }
        edges[node].size = count;
    }

    initDfs(1, V);
    dfs(1, 0);
    
    int fardest = fardest_node;
    initDfs(fardest, V);
    dfs(fardest, 0);

    std::cout << max_dist << "\n";

    return 0;
}