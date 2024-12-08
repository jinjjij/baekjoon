#include <iostream>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T = 0;
    std::cin >> T;

    int score[5] = {0,};
    for(int t=0;t<T;t++){
        std::cin >> score[t];
    }

    int result[3] = {0,};

    if(score[0] > score[2]){
        result[0] = (score[0] - score[2]) * 508;
    }else{
        result[0] = (score[2] - score[0]) * 108;
    }
    if(score[1] > score[3]){
        result[1] = (score[1] - score[3]) * 212;
    }else{
        result[1] = (score[3] - score[1]) * 305;
    }
    if(T==5){
        result[2] = score[4] * 707;
    }

    std::cout << (result[0] + result[1] + result[2]) * 4763;

    return 0;
}