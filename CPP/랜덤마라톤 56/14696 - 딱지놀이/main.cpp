#include <iostream>
#include <vector>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    int a,b;
    std::vector<int> count;

    int tmp;
    for(int i=0;i<N;i++){
        count = {0,0,0,0,0};

        std::cin >> a;
        for(int j=0;j<a;j++){
            std::cin >> tmp;
            count[tmp] ++;
        }
        std::cin >> b;
        for(int j=0;j<b;j++){
            std::cin >> tmp;
            count[tmp] --;
        }

        char ret = 'D';
        for(int i=4;i>=1;i--){
            if(count[i]>0){
                ret = 'A';
                break;
            }else if(count[i]<0){
                ret = 'B';
                break;
            }
        }
        std::cout << ret << "\n";
    }


    

    return 0;
}