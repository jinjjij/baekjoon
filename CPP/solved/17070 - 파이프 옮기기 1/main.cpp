#include <iostream>




int N = 0;
int arr[16][16];

int count = 0;


/* 
    state : 
    0 : 가로
    1 : 세로
    2 : 대각선
*/
int checkbound(int x, int y){
    return (x>=0 && y>=0 && x<N && y<N && !arr[x][y]);
}


int checkWall(int x, int y, int state){
    int ret = 0;
    if(!checkbound(x,y)) return 0;
    switch(state){
    case 0:         // 가로
        ret = checkbound(x,y+1);
        break;
    case 1:         // 세로
        ret = checkbound(x+1,y);
        break;
    case 2:         // 대각선
        ret = checkbound(x+1,y) && checkbound(x,y+1) && checkbound(x+1,y+1);
        break;
    default:
        break;
    }

    return ret;
}


int checkEnd(int x, int y, int state){
    if(x==N-1 && y==N-2 && state==0){
        return 1;
    }
    if(x==N-2 && y==N-1 && state==1){
        return 1;
    }
    if(x==N-2 && y==N-2 && state==2){
        return 1;
    }
    return 0;
}


void dfs(int x, int y, int state){
    if(checkEnd(x,y,state)){
        count ++;
        return;
    }

    switch(state){
        case 0:
            if(checkWall(x,y+1,0))  dfs(x,y+1,0);
            if(checkWall(x,y+1,2))  dfs(x,y+1,2);
        break;
        case 1:
            if(checkWall(x+1,y,1))  dfs(x+1,y,1);
            if(checkWall(x+1,y,2))  dfs(x+1,y,2);
        break;
        case 2:
            if(checkWall(x+1,y+1,0))  dfs(x+1,y+1,0);
            if(checkWall(x+1,y+1,1))  dfs(x+1,y+1,1);
            if(checkWall(x+1,y+1,2))  dfs(x+1,y+1,2);
        break;
    }
}



int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    count = 0;
    std::cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            std::cin >> arr[i][j];
        }
    }

    dfs(0,0,0);

    std::cout << count << "\n";
    return 0;
}