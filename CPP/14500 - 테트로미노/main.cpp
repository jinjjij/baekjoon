#include <iostream>

int arr[500][500];
int vis[500][500];
int N,M;
int max = 0;
int sum = 0;


bool isInBound(int x, int y){
    if(x<0||x>=N||y<0||y>=M)    return false;
    else                        return true;
}


int dfs(int x, int y, int depth){

    if(depth == 4){
        // ㅗ모양
        int sides = 0;
        int values[4];
        if(isInBound(x-1, y))   sides++;
        
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    
    std::cin >> N;
    std::cin >> M;

    
    /*
    visited rule
    0 -> not at all visited
    1 -> visited in process
    2 -> process ended
    */
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            std::cin >> arr[i][j];
            vis[i][j] = 0;
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            sum = arr[i][j];
            vis[i][j] = 1;
            dfs(i, j, 4);
        }
    }

    std::cout << max;

    return 0;
}