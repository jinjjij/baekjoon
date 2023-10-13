#include <iostream>

int arr[500][500];
int N,M;


int max(int a, int b){
    return a>b?a:b;
}


bool isInBound(int x, int y){
    if(x<0||x>=N||y<0||y>=M)    return false;
    else                        return true;
}


int check(int x, int y){
    int ret = 0;
    //I
    if(isInBound(x+3,y)){
        ret = max(ret, arr[x][y]+arr[x+1][y]+arr[x+2][y]+arr[x+3][y]);
    }
    if(isInBound(x,y+3)){
        ret = max(ret, arr[x][y]+arr[x][y+1]+arr[x][y+2]+arr[x][y+3]);
    }
    //L
        /*
        OO  O   OO   O  OOO O   OOO   O
        O   O    O   O  O   OOO   O OOO
        O   OO   O  OO
        */
    if(isInBound(x+1,y+2)){
        ret = max(ret, arr[x][y]+arr[x+1][y]+arr[x][y+1]+arr[x][y+2]);
        ret = max(ret, arr[x][y]+arr[x][y+1]+arr[x][y+2]+arr[x+1][y+2]);
        ret = max(ret, arr[x][y]+arr[x+1][y]+arr[x+1][y+1]+arr[x+1][y+2]);
        ret = max(ret, arr[x+1][y]+arr[x+1][y+1]+arr[x+1][y+2]+arr[x][y+2]);
    }
    if(isInBound(x+2,y+1)){
        ret = max(ret, arr[x][y]+arr[x+1][y]+arr[x+2][y]+arr[x][y+1]);
        ret = max(ret, arr[x][y]+arr[x][y+1]+arr[x+1][y+1]+arr[x+2][y+1]);
        ret = max(ret, arr[x][y]+arr[x+1][y]+arr[x+2][y]+arr[x+2][y+1]);
        ret = max(ret, arr[x][y+1]+arr[x+1][y+1]+arr[x+2][y+1]+arr[x+2][y]);
    }

    //ㅁ
    if(isInBound(x+1,y+1)){
        ret = max(ret, arr[x][y]+arr[x+1][y]+arr[x][y+1]+arr[x+1][y+1]);
    }
    //ㅗ
    /*
        O    O   O  OOO
        OO  OO  OOO  O
        O    O
    */
    if(isInBound(x+1,y+2)){
        ret = max(ret, arr[x][y]+arr[x][y+1]+arr[x][y+2]+arr[x+1][y+1]);
        ret = max(ret, arr[x][y+1]+arr[x+1][y]+arr[x+1][y+1]+arr[x+1][y+2]);
    }
    if(isInBound(x+2,y+1)){
        ret = max(ret, arr[x+1][y]+arr[x][y+1]+arr[x+1][y+1]+arr[x+2][y+1]);
        ret = max(ret, arr[x][y]+arr[x+1][y]+arr[x+2][y]+arr[x+1][y+1]);
    }
    //ㄹ
    /*
        OO   OO O    O
         OO OO  OO  OO
                 O  O
    
    */
    if(isInBound(x+2,y+1)){
        ret = max(ret, arr[x][y]+arr[x+1][y]+arr[x+1][y+1]+arr[x+2][y+1]);
        ret = max(ret, arr[x][y+1]+arr[x+1][y+1]+arr[x+1][y]+arr[x+2][y]);
    }
    if(isInBound(x+1,y+2)){
        ret = max(ret, arr[x][y]+arr[x][y+1]+arr[x+1][y+1]+arr[x+1][y+2]);
        ret = max(ret, arr[x+1][y]+arr[x+1][y+1]+arr[x][y+1]+arr[x][y+2]);
    }

    return ret;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    
    std::cin >> N;
    std::cin >> M;
    int ret = 0;

    
    /*
    visited rule
    0 -> not at all visited
    1 -> visited in pro cess
    2 -> process ended
    */
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            std::cin >> arr[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            ret = max(ret, check(i,j));
        }
    }

    std::cout << ret << "\n";

    return 0;
}