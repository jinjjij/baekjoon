#include <iostream>

int n,m;
int board[100][100];
bool vis[100][100];


void _DebugBoard(){
    std::cout << "marked board : \n";
    for(int i=0;i<n;i++){for(int j=0;j<m;j++){
        if(board[i][j]==1)  std::cout << " ";
        std::cout << board[i][j] << " ";
    }std::cout << "\n";}
}


void initVis(){
    for(int i=0;i<n;i++){for(int j=0;j<m;j++){
        vis[i][j] = 0;
    }}
}


bool isInBound(int r, int c){
    if(r<0||r>=n||c<0||c>=m){
        return false;
    }else{
        return true;
    }
}


void _MarkOpenCell(int r, int c){
    if(!isInBound(r,c)) return;
    if(vis[r][c])      return;
    vis[r][c] = 1;

    if(board[r][c] == 0){
        board[r][c] = -1;

        _MarkOpenCell(r-1,c);
        _MarkOpenCell(r+1,c);
        _MarkOpenCell(r,c-1);
        _MarkOpenCell(r,c+1);
    }
}


/*
    MarkOpenSpace()
    mark open space in board[][] as -1;
*/
void MarkOpenSpace(void){
    initVis();
    for(int i=0;i<n;i++){for(int j=0;j<m;j++){
        if(i==0||i==n-1||j==0||j==m-1)  _MarkOpenCell(i,j);
    }}
}


void MarkCheese(void){
    for(int i=0;i<n;i++){for(int j=0;j<m;j++){
        if(board[i][j] != 1)    continue;
        int adj_count = 0;

        if(isInBound(i-1,j) && board[i-1][j] == -1) adj_count++;    
        if(isInBound(i+1,j) && board[i+1][j] == -1) adj_count++;
        if(isInBound(i,j-1) && board[i][j-1] == -1) adj_count++;
        if(isInBound(i,j+1) && board[i][j+1] == -1) adj_count++;

        if(adj_count >= 2){
            board[i][j] = -2;
        }
    }}
}


/*
    Displace -2 with -1
*/
void DeleteCheese(void){
    for(int i=0;i<n;i++){for(int j=0;j<m;j++){
        if(board[i][j] == -2)    board[i][j] = -1;
    }}
}


bool checkCheese(void){
    bool ret = false;
    for(int i=0;i<n;i++){for(int j=0;j<m;j++){
        if(board[i][j] == 1)    ret = true;
    }}

    return ret;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> n >> m;
    for(int i=0;i<n;i++){for(int j=0;j<m;j++){
        std::cin >> board[i][j];
    }}

    int time = 0;
    
    while(1){
        time++;

        // step
        MarkOpenSpace();
        MarkCheese();
        DeleteCheese();

        // check cheese
        if(!checkCheese()){
            break;
        }
    }

    std::cout << time;
    
    return 0;
}
