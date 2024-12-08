#include <iostream>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    int t[100];
    for(int i=0;i<M;i++){
        std::cin >> t[i];
    }

    int max_value = 0;
    int max_team = 1;

    int tmp;
    for(int i=1;i<=N;i++){
        //std::cout << i << " th team : ";

        int score = 0;
        for(int j=0;j<M;j++){
            std::cin >> tmp;
            if(t[j] == tmp){
                score ++;
            }
        }

        //std::cout << score << "\n";
        if(max_value < score){
            max_team = i;
            max_value = score;
        }
    }

    std::cout << max_team;
    return 0;
}