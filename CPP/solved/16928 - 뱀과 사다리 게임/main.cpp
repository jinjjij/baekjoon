#include <iostream>
#include <queue>
#include <utility>


// index = arrive cell
// value = departure cell
int snake[101];
int minData[101];


int min(int a, int b){
    return a<b?a:b;
}


void initArrays(void){
    for(int i=0;i<101;i++){
        snake[i] = 0;
        minData[i] = 111111;
    }
}



int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N,M = 0;
    std::cin >> N;
    std::cin >> M;

    initArrays();

    int dep, arr;
    for(int i=0;i<N+M;i++){
        std::cin >> dep;
        std::cin >> arr;
        snake[dep] = arr;
    }

    int ret = 0;
    std::queue<std::pair<int, int>> myq;

    myq.push(std::make_pair(1, 0));

    std::pair<int,int> cur;
    int pos, lev;
    while(!myq.empty()){
        cur = myq.front();
        myq.pop();
        pos = cur.first;
        lev = cur.second;

        if(minData[pos] < lev){
            continue;
        }else{
            minData[pos] = lev;
        }

        if(snake[pos] != 0) pos = snake[pos];

        if(pos == 100){
            ret = lev;
            break;
        }

        for(int i=6;i>=1;i--){
            if(pos+i <= 100){
                myq.push(std::make_pair(pos+i, lev+1));
            }
        }
    }

    std::cout << ret << "\n";


    return 0;
}