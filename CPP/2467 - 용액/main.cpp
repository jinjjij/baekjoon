#include <iostream>
#include <vector>
#include <algorithm>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<int> input(N);

    for(int i=0;i<N;i++){
        std::cin >> input[i];
    }

    


    return 0;
}

/*
-99 -2  -1  4   98
0   97  98  

*/