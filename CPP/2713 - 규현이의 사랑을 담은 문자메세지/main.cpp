#include <iostream>



typedef struct{ 
    int x;
    int y;
    int dir;
} duo;


void getBinary(char c, int* result){
    int ascii = 0;
    if(c == ' '){
        ascii = 0;
    }else{
        ascii = c-'A'+1;
    }

    for(int i=0;i<5;i++){
        result[4-i] = ascii%2;
        ascii /= 2;
    }
}


bool checkPos(int (*vis)[21], duo pos, int row, int col){
    if(pos.x<0||pos.y<0){
        return false;
    }
    if(pos.x>=col||pos.y>=row){
        return false;
    }
    if(vis[pos.x][pos.y]){
        return false;
    }
    return true;
}



int updateDir(duo cur, int (*vis)[21], int row, int col){
    duo npos[4] = {
        {cur.dir, cur.x, cur.y+1},
        {cur.dir, cur.x+1, cur.y},
        {cur.dir, cur.x, cur.y-1},
        {cur.dir, cur.x-1, cur.y}
    };
    bool avail[4] = {
        checkPos(vis, npos[0], row, col),
        checkPos(vis, npos[1], row, col),
        checkPos(vis, npos[2], row, col),
        checkPos(vis, npos[3], row, col)
    };
         if(cur.dir==0){if(!avail[cur.dir])   return 1;}
    else if(cur.dir==1){if(!avail[cur.dir])   return 2;}
    else if(cur.dir==2){if(!avail[cur.dir])   return 3;}
    else if(cur.dir==3){if(!avail[cur.dir])   return 0;}
    else                                      return -1;
    return cur.dir;
}


duo NextPos(duo cur, int (*vis)[21], int row, int col){
    duo npos[4] = {
        {cur.dir, cur.x, cur.y+1},
        {cur.dir, cur.x+1, cur.y},
        {cur.dir, cur.x, cur.y-1},
        {cur.dir, cur.x-1, cur.y}
    };
    bool avail[4] = {
        checkPos(vis, npos[0], row, col),
        checkPos(vis, npos[1], row, col),
        checkPos(vis, npos[2], row, col),
        checkPos(vis, npos[3], row, col)
    };
    

    if(avail[cur.dir]){
        npos[cur.dir].dir = updateDir(npos[cur.dir], vis, row, col);
    }else{
        return {-1,-1,-1};
    }

}


std::string Convert(int r, int c, std::string input){
    int arr[21][21];
    int vis[21][21];
    for(int i=0;i<21;i++){for(int j=0;j<21;j++){arr[i][j] = 0;vis[i][j] = 0;}}

    int ch[5] = {0,};
    duo pos = {0,0,0};

    for(int i=0;i<input.length();i++){
        getBinary(input[i], ch);
        

        for(int j=0;j<5;j++){
            std::cout << ch[j];
            /*
            arr[pos.x][pos.y] = ch[j];
            pos = NextPos(pos, vis, r, c);

            if(pos.dir == -1 && pos.x == -1 && pos.y == -1){
                break;
            }
            */
        }
        std::cout << "\n";
        
    }

    std::string output = "";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            output += std::to_string(arr[i][j]);
        }
    }

    return output;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T = 0;
    std::cin >> T;

    int r,c;
    std::string input = "";
    for(int t=0;t<T;t++){
        std::cin >> r >> c;
        std::cin >> input;
        std::cout << Convert(r,c,input) << "\n";
    }
    
    return 0;
}
