#include <iostream>
#include <vector>


int R,C;
std::vector<std::vector<char>> input;
std::vector<std::vector<bool>> vis;
std::vector<bool> alphaVis;


int max2(int a, int b){
    return a>b?a:b;
}


bool isInBorder(int r, int c){
    if(r>=0 && r<R && c>=0 && c<C)  return true;
    else    return false;
}


int dfs(int r, int c, int dist){ 
    if(!isInBorder(r,c))   return 0;
    if(vis[r][c])  return 0;
    if(alphaVis[input[r][c]-'0'])   return 0;

    //fprintf(stderr, "%d, %d\n", r,c);
    
    int max = dist;

    vis[r][c] = true;
    alphaVis[input[r][c]-'0'] = true;

    max = max2(max, dfs(r-1, c, dist+1));
    max = max2(max, dfs(r+1, c, dist+1));
    max = max2(max, dfs(r, c-1, dist+1));
    max = max2(max, dfs(r, c+1, dist+1));

    vis[r][c] = false;
    alphaVis[input[r][c]-'0'] = false;

    return max;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> R >> C;

    input.resize(R);
    vis.resize(R);
    alphaVis.resize(26,false);
    for(int i=0;i<R;i++){
        input[i].resize(C);
        vis[i].resize(C, false);
        for(int j=0;j<C;j++){
            std::cin >> input[i][j];
        }
    }

    std::cout << dfs(0,0,1);
    
    return 0;
}