#include <iostream>
#include <vector>





int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::vector<std::vector<int>> input;
    input.resize(9);
    for(int i=0;i<9;i++){
        input[i].resize(9);
        for(int j=0;j<9;j++)
            std::cin >> input[i][j];
    }



    return 0;
}