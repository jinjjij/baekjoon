#include <iostream>
#include <vector>


std::vector<std::vector<int>> board, next;
int R,C,T;
int up, down;

bool isInRange(int r, int c){
    if(r>=0 && r < R && c>=0 && c < C)
        return true;
    else
        return false;
}


void debug(){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            fprintf(stderr, "%d ", board[i][j]);
        }
        fprintf(stderr, "\n");
    }
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    up = -1;
    
    std::cin >> R >> C >> T;

    board.resize(R);
    for(int i=0;i<R;i++){
        board[i].resize(C);
        for(int j=0;j<C;j++){
            std::cin >> board[i][j];
            if(board[i][j] == -1){
                if(up == -1)    up = i;
                else            down = i;
            }
        }   
    }

    while(T>0){
        next = board;

        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(board[i][j] == 0)    continue;
                int spreadAmount = board[i][j]/5;

                if(isInRange(i-1,j) && board[i-1][j] != -1){
                    next[i-1][j] += spreadAmount;
                    next[i][j] -= spreadAmount;
                }
                if(isInRange(i+1,j) && board[i+1][j] != -1){
                    next[i+1][j] += spreadAmount;
                    next[i][j] -= spreadAmount;
                }
                if(isInRange(i,j-1) && board[i][j-1] != -1){
                    next[i][j-1] += spreadAmount;
                    next[i][j] -= spreadAmount;
                }
                if(isInRange(i,j+1) && board[i][j+1] != -1){
                    next[i][j+1] += spreadAmount;
                    next[i][j] -= spreadAmount;
                }

            }   
        }

        board = next;
        //debug();

        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                // 오른쪽으로
                if((i==up || i==down)){
                    if(j==0)    continue;
                    if(j==1)    next[i][j] = 0;
                    else        next[i][j] = board[i][j-1];
                }

                // 왼쪽으로
                if(i==0 || i==R-1){
                    if(j!=C-1)
                        next[i][j] = board[i][j+1];
                }

                // 위쪽으로
                if( i>down && i!=R-1 && j==0 ){
                    next[i][j] = board[i+1][j];
                }
                if( i<up && j==C-1 ){
                    next[i][j] = board[i+1][j];
                }

                //아래쪽으로
                if( i<up && i!=0 && j==0 ){
                    next[i][j] = board[i-1][j];
                }
                if( i>down && j==C-1 ){
                    next[i][j] = board[i-1][j];
                }
            }
        }

        board = next;
        //fprintf(stderr, "\n");
        //debug();



        T--;
    }

    int count = 0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(board[i][j] != -1){
                count += board[i][j];
            }
        }
    }

    std::cout << count;

    return 0;
}