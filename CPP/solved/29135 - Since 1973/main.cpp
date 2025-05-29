#include <iostream>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 0;
    std::cin >> N;

    int count = 0;
    for(int i=1;i<N;i++){
        count ++;

        int tmp = i;
        while(tmp>=50){
            if(tmp%100 == 50){
                count++;
                break;
            }
            tmp /= 10;
        }
    }
    count++;

    std::cout << count;
    
    return 0;
}