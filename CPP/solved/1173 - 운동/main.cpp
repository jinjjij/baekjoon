#include <iostream>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N,m,M,T,R;

    std::cin >> N >> m >> M >> T >> R;

    int count = 0;
    int elapsedTime = 0;
    int cur = m;
    while(true){
        if(cur+T >= m && cur+T <= M){
            cur += T;
            count ++;
        }else{
            if(cur == m){
                break;
            }
            cur -= R;
            if(cur < m){
                cur = m;
            }
        }
        elapsedTime ++;

        if(count == N){
            break;
        }
    }

    if(count != N){
        elapsedTime = -1;
    }
    
    std::cout << elapsedTime;
    return 0;
}