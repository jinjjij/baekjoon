#include <iostream>
#include <vector>
#include <queue>


typedef struct node{
    int r,c,dist,broken;
} node;


int N,M;
std::vector<std::vector<std::vector<bool>>> vis;
std::vector<std::vector<int>> input;
std::queue<node> q;




void checkandPush(int curBroken, node n){
    if(n.r < 0 || n.r >= N) return;
    if(n.c < 0 || n.c >= M) return;

    if(curBroken){
        if(input[n.r][n.c] == 0 && !vis[n.r][n.c][n.broken]){
            q.push({n.r, n.c, n.dist, curBroken});
            vis[n.r][n.c][curBroken] = true;
        }
    }else{
        if(!vis[n.r][n.c][input[n.r][n.c]]){
            q.push({n.r, n.c, n.dist, input[n.r][n.c]});
            vis[n.r][n.c][input[n.r][n.c]] = true;
        }
        
    } 
    
}



int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N >> M;

    vis.resize(N);
    input.resize(N);

    char c;
    for(int i=0;i<N;i++){
        input[i].resize(M);
        vis[i].resize(M);
        for(int j=0;j<M;j++){
            std::cin >> c;
            input[i][j] = c-'0';
            vis[i][j] = {false,false};
        }
    }


    
    q.push({0,0,1,0});
    int result = -1;

    while(!q.empty()){
        node cur = q.front();   q.pop();
        //std::cout << cur.r << ", " << cur.c << "\n";
        

        if(cur.r == N-1 && cur.c == M-1){
            result = cur.dist;
            break;
        }

        checkandPush(cur.broken, {cur.r-1, cur.c, cur.dist+1, cur.broken});
        checkandPush(cur.broken, {cur.r+1, cur.c, cur.dist+1, cur.broken});
        checkandPush(cur.broken, {cur.r, cur.c-1, cur.dist+1, cur.broken});
        checkandPush(cur.broken, {cur.r, cur.c+1, cur.dist+1, cur.broken});
    }
    
    std::cout << result;
    return 0;
}