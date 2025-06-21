#include <iostream>
#include <vector>


typedef std::vector<std::vector<char>> board;
board cur, next;
int N, M;

/*
    0 - original air
    1 - cheese
    2 - exposed air

*/


bool inBorder(int r, int c){
    if(r>=0 && r<N && c>=0 && c<M) return true;
    else        return false;
}


void _airDfs(std::vector<std::vector<bool>>& vis, int r, int c){
    vis[r][c] = true;
    next[r][c] = 2;

    if(inBorder(r-1, c) && !vis[r-1][c] && cur[r-1][c] != 1)    _airDfs(vis, r-1, c);
    if(inBorder(r+1, c) && !vis[r+1][c] && cur[r+1][c] != 1)    _airDfs(vis, r+1, c);
    if(inBorder(r, c-1) && !vis[r][c-1] && cur[r][c-1] != 1)    _airDfs(vis, r, c-1);
    if(inBorder(r, c+1) && !vis[r][c+1] && cur[r][c+1] != 1)    _airDfs(vis, r, c+1);
}


void AirSimulation(){
    std::vector<std::vector<bool>> vis(N);
    for(int i=0;i<N;i++)    vis[i].resize(M, false);

    _airDfs(vis, 0, 0);
}


bool cheeseSimulation(){
    bool flg = false;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(cur[i][j] == 1){
                flg = true;
                int count = 0;
                if(inBorder(i-1, j) && cur[i-1][j] == 2)    count++; 
                if(inBorder(i+1, j) && cur[i+1][j] == 2)    count++;
                if(inBorder(i, j-1) && cur[i][j-1] == 2)    count++;
                if(inBorder(i, j+1) && cur[i][j+1] == 2)    count++;

                if(count >= 2){
                    next[i][j] = 2;
                }
            }
        }
    }

    return flg;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N >> M;

    cur.resize(N);

    char inputChar;
    for(int i=0;i<N;i++){
        cur[i].resize(M, 0);
        for(int j=0;j<M;j++){
            std::cin >> inputChar;
            if(i==0 || i==N-1 || j==0 || j==M-1){
                cur[i][j] = 2;
            }else{
                cur[i][j] = inputChar - '0';
            }
        }
    }


    int count = 0;
    while(true){
        next = cur;

        // 공기 시뮬레이션
        AirSimulation();
        cur = next;

        // 치즈 시뮬
        if(cheeseSimulation()){
            count++;
        }else{
            break;
        }

        // cur <-> next 스왑
        cur = next;

        // (디버그 : next 출력)
        
    }
    
    std::cout << count;
    
    return 0;
}