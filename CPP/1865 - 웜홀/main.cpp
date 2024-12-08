#include <iostream>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T = 0;

    int N = 0;
    int M = 0;
    int W = 0;
    int S = 0;
    int E = 0;
    int T = 0;
    int road[501][501] = {0};

    for(int t=0; t<T; t++){
        std::cin >> N;
        std::cin >> M;
        std::cin >> W;
        init2dimArr(road, N+1);

        for(int m=0; m<M; m++){       // 도로 입력       
            std::cin >> S;
            std::cin >> E;
            std::cin >> T;

            if(road[S][E] == 0 || T < road[S][E]){
                road[S][E] = T;
            }
            if(road[E][S] == 0 || T < road[E][S]){
                road[E][S] = T;
            }
        }
        for(int w=0; w<W; w++){       // 웜홀 입력       
            std::cin >> S;
            std::cin >> E;
            std::cin >> T;

            if(-T < road[S][E]){
                road[S][E] = -T;
            }
        }



    }
    return 0;
}


template <size_t rows, size_t cols>
void init2dimArr(int (&arr)[rows][cols], int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            arr[i][j] = 0;
        }
    }
}