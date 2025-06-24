#include <iostream>
#include <vector>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 0;
    std::cin >> N;
    int count = 1;
    int size = 0;
    int max = 0;

    int cur = 0;
    int prev = -1;
    for(int i=0;i<N;i++){
        std::cin >> cur;

        if(cur >= prev){
            size ++;
        }else{
            max = max>size?max:size;
            size = 1;
            count ++;
        }

        prev = cur;
    }
    max = max>size?max:size;

    std::cout << count << " " << max;

    return 0;
}