#include <iostream>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 0;
    std::cin >> N;

    int size[6] = {0,};

    for(int i=0;i<6;i++){
        std::cin >> size[i];
    }

    int T,P;
    std::cin >> T;
    std::cin >> P;

    int output = 0;

    for(int i=0;i<6;i++){
        output += (size[i]%T)?size[i]/T+1:size[i]/T;
    }
    std::cout << output << "\n" << N/P << " " << N%P;

    return 0;
}