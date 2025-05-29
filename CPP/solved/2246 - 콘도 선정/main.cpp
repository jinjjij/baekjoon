#include <iostream>
#include <vector>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<int> Cost(N);
    std::vector<int> Dist(N);


    for(int i=0;i<N;i++){
        std::cin >> Dist[i] >> Cost[i];
    }


    int count = 0;
    for(int i=0;i<N;i++){
        bool flag = true;
        for(int j=0;j<N;j++){
            if((Dist[i] > Dist[j] && Cost[i] >= Cost[j]) || (Cost[i] > Cost[j] && Dist[i] >= Dist[j])){
                flag = false;
                break;
            }
        }
        if(flag){
            count++;
        }
    }


    std::cout << count;
    
    return 0;
}