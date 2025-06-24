#include <iostream>
#include <vector>
#include <algorithm>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> cards(N+1);
    for(int i=1;i<N+1;i++){
        cards[i].resize(M,0);
        for(int j=0;j<M;j++){
            std::cin >> cards[i][j];
        }

        std::sort(cards[i].begin(), cards[i].end(), std::greater<int>());
    }

    std::vector<int> score(N+1, 0);
    for(int i=0;i<M;i++){
        int max = 0;
        for(int j=1;j<=N;j++){
            max = max>cards[j][i]?max:cards[j][i];
        }

        for(int j=1;j<=N;j++){
            if(max == cards[j][i])
                score[j] ++;
        }
    }

    int maxScore = 0;
    for(int i=1;i<=N;i++){
        maxScore = maxScore > score[i]?maxScore : score[i];
    }

    for(int i=1;i<=N;i++){
        if(score[i] == maxScore){
            std::cout << i << " ";
        }
    }

    return 0;
}