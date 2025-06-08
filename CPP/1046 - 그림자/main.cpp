#include <iostream>
#include <vector>


typedef std::pair<double, double> coord;




int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N ,M;
    std::cin >> N >> M;
    std::cin.get();

    // 장애물의 꼭짓점 좌표들 + 4개의 구석 추출
    std::vector<coord> corners;
    coord light;

    char input;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            std::cin >> input;
            
            if(input == '*'){
                light = {i,j};
            }

        }
        std::cin.get();
    }

    // 좌표들을 각도별로 정렬

    // 삼각형들 넓이를 더함
    
    return 0;
}