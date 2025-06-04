#include <iostream>
#include <vector>


std::pair<int, int> nextPos(std::pair<int, int> vis, std::pair<int, int> cur, int R, int C){

}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T,R,C;;
    std::cin >> T;
    std::string inputStr;

    for(int t=0;t<T;t++){
        std::cin >> R >> C >> inputStr;
        std::vector<std::vector<int>> arr(R);
        std::vector<std::vector<bool>> vis(R);
        for(int i=0;i<R;i++){
            arr[i].resize(T, 0);
            vis[i].resize(T, false);
        }

        // process
        std::pair<int, int> pos = {0, 0};

        for(int i=0;i<inputStr.size();i++){

        }

        // output
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                std::cout << arr[i][j];
            }
        }
        std::cout << "\n";
    }
    
    return 0;
}
