#include <iostream>
#include <vector>


typedef std::pair<int, int> coord;


int min(int a, int b){
    return a<b?a:b;
}


int abs(int a){
    return a>0?a:-a;
}


int dist(coord a, coord b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N,M;
    std::cin >> N >> M;
    std::vector<coord> chicken;
    std::vector<coord> house;
    std::vector<std::vector<int>> chickDist;


    int input = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            std::cin >> input;
            if(input == 1){
                house.push_back({i, j});
            }else if(input == 2){
                chicken.push_back({i, j});
            }
        }
    }

    int cN = chicken.size();
    int hN = house.size();
    chickDist.resize(hN);

    for(int i=0;i<hN;i++){
        chickDist[i].resize(cN);
        for(int j=0;j<cN;j++){
            chickDist[i][j] = dist(house[i], chicken[j]);
        }
    }


    int bit = (1<<M)-1;
    int minDist = INT32_MAX;

    while(bit < (1<<chicken.size())){
        // 도시의 치킨 거리 구하기

        int cityDist = 0;
        for(int i=0;i<hN;i++){
            int houseMin = INT32_MAX;
            for(int j=0;j<cN;j++){
                if(bit & (1 << j)){
                    houseMin = min(houseMin, chickDist[i][j]);
                }
            }
            cityDist += houseMin;
        }

        minDist = min(minDist, cityDist);


        int c = bit & -bit;
        int r = bit + c;
        bit = (((bit ^ r) >> 2) / c) | r;
    }
    
    std::cout << minDist;
    
    return 0;
}