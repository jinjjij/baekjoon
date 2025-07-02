#include <iostream>
#include <vector>



int findMax(std::vector<int>& arr){
    std::pair<int, int> max = {0, -1};

    for(int i=1;i<arr.size();i++){
        if(arr[i] > max.second){
            max = {i, arr[i]};
        }
    }

    return max.first;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<int> input[4];

    for(std::vector<int>& v : input){
        v.resize(N+1, 0);
    }

    int index, tmp;
    for(int i=0;i<N;i++){
        std::cin >> index;
        for(int j=0;j<4;j++){
            std::cin >> tmp;
            input[j][index] = tmp;
        }
    }
    
    int out[4];
    for(int i=0;i<4;i++){
        out[i] = findMax(input[i]);
        for(int j=i+1;j<4;j++)
            input[j][out[i]] = -1;
        std::cout << out[i] << " ";
    }

    return 0;
}