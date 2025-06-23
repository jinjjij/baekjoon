#include <iostream>
#include <vector>
#include <queue>



typedef std::pair<int, int> coord;

int N, M;
std::vector<std::vector<int>> board;
std::vector<coord> empty, wall, virus;


bool isInRange(int r, int c){
    if(0<=r && r<N && 0<=c && c<M)  return true;
    else    return false;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N >> M;
    int input = 0;
    board.resize(N);
    for(int i=0;i<N;i++){
        board[i].resize(M);
        for(int j=0;j<M;j++){
            std::cin >> input;
            if(input == 0){
                empty.push_back({i,j});
            }else if(input == 1){
                wall.push_back({i,j});
            }else{
                virus.push_back({i,j});
            }
            board[i][j] = input;
        }
    }


    std::vector<std::vector<int>> newboard;
    int max = 0;

    for(int i=0;i<empty.size();i++){
        for(int j=i+1;j<empty.size();j++){
            for(int k=j+1;k<empty.size();k++){
                newboard = board;
                newboard[empty[i].first][empty[i].second] = 1;
                newboard[empty[j].first][empty[j].second] = 1;
                newboard[empty[k].first][empty[k].second] = 1;

                std::queue<coord> q;
                for(coord c : virus){
                    q.push(c);
                }

                while(!q.empty()){
                    coord cur = q.front();  q.pop();

                    int r = cur.first;  int c = cur.second;

                    if(isInRange(r-1,c) && newboard[r-1][c] == 0){
                        newboard[r-1][c] = 2;
                        q.push({r-1,c});
                    }
                    if(isInRange(r+1,c) && newboard[r+1][c] == 0){
                        newboard[r+1][c] = 2;
                        q.push({r+1,c});
                    }
                    if(isInRange(r,c-1) && newboard[r][c-1] == 0){
                        newboard[r][c-1] = 2;
                        q.push({r,c-1});
                    }
                    if(isInRange(r,c+1) && newboard[r][c+1] == 0){
                        newboard[r][c+1] = 2;
                        q.push({r,c+1});
                    }
                }

                int count = 0;
                for(int a=0;a<N;a++){
                    for(int b=0;b<M;b++){
                        if(newboard[a][b] == 0)     count ++;
                    }
                }
                if(max < count) max = count;

            }
        }
    }


    std::cout << max;
    
    
    return 0;
}