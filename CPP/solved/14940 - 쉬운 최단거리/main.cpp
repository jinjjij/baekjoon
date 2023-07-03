#include <iostream>
#include <queue>
#include <tuple>




bool _checkBound(std::pair<int, int> pos, std::pair<int, int> bound){
    bool ret = false;
    if( pos.first < 0 || 
        pos.second < 0 || 
        pos.first >= bound.first || 
        pos.second >= bound.second){
        ret = false;
    }else{
        ret = true;
    }

    //std::cout << "[_checkBound(" << pos.first << ", " << pos.second << ")]\n";
    return ret;
}   



int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    int arr[n][m];
    int out_arr[n][m] = {0,};
    int visited[n][m] = {0,};
    std::tuple<int, int, int> startpos(0,0,0);

    // input
    int temp_input = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            std::cin >> temp_input;
            visited[i][j] = 0;
            if(temp_input==2){
                startpos = std::tuple<int, int, int>(i,j,0);
                visited[i][j] = 1;
            }
            arr[i][j] = temp_input;
            out_arr[i][j] = -1;
        }
    }

    // process
    std::queue<std::tuple<int, int, int>> bfs_queue;
    bfs_queue.push(startpos);

    while(!bfs_queue.empty()){
        std::tuple<int, int, int> cur = bfs_queue.front();
        bfs_queue.pop();

        int x = std::get<0>(cur);
        int y = std::get<1>(cur);
        int dist = std::get<2>(cur);
        out_arr[x][y] = dist;
        

        //std::cout << "visited : " << x << ", " << y << ", " << dist << "\n";

        //up
        if(_checkBound(std::pair<int, int>(x-1, y), std::pair<int, int>(n, m)) && !visited[x-1][y] && arr[x-1][y]!=0){
            bfs_queue.push(std::tuple<int, int, int>(x-1, y, dist+1));
            visited[x-1][y] = 1;
        }
        //right
        if(_checkBound(std::pair<int, int>(x, y+1), std::pair<int, int>(n, m)) && !visited[x][y+1] && arr[x][y+1]!=0){
            bfs_queue.push(std::tuple<int, int, int>(x, y+1, dist+1));
            visited[x][y+1] = 1;
        }
        //down
        if(_checkBound(std::pair<int, int>(x+1, y), std::pair<int, int>(n, m)) && !visited[x+1][y] && arr[x+1][y]!=0){
            bfs_queue.push(std::tuple<int, int, int>(x+1, y, dist+1));
            visited[x+1][y] = 1;
        }
        //left
        if(_checkBound(std::pair<int, int>(x, y-1), std::pair<int, int>(n, m)) && !visited[x][y-1] && arr[x][y-1]!=0){
            bfs_queue.push(std::tuple<int, int, int>(x, y-1, dist+1));
            visited[x][y-1] = 1;
        }
    }


    // output
    int printInt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 0){
                printInt = 0;
            }else{
                printInt = out_arr[i][j];
            }
            std::cout << printInt << " ";
        }
        std::cout << "\n";
    }

    return 0;
}