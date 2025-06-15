#include <iostream>
#include <vector>

int max2(int a, int b){
    return a>b?a:b;
}

int max3(int a, int b, int c){
    return max2(a, max2(b,c));
}

int min2(int a, int b){
    return a<b?a:b;
}

int min3(int a, int b, int c){
    return min2(a, min2(b,c));
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;
    
    int input[3];
    int max[3] = {0,0,0};
    int min[3] = {INT32_MAX};
    int curmax[3];
    int curmin[3];

    for(int i=0;i<N;i++){
        std::cin >> input[0] >> input[1] >> input[2];
        
        curmax[0] = max2(max[0], max[1]) + input[0];
        curmax[1] = max3(max[0], max[1], max[2]) + input[1];
        curmax[2] = max2(max[1], max[2]) + input[2];

        curmin[0] = min2(min[0], min[1]) + input[0];
        curmin[1] = min3(min[0], min[1], min[2]) + input[1];
        curmin[2] = min2(min[1], min[2]) + input[2];

        for(int i=0;i<3;i++){
            max[i] = curmax[i];
            min[i] = curmin[i];
        }
    }

    std::cout << max3(max[0], max[1], max[2]) << " " << min3(min[0], min[1], min[2]);
    return 0;
}