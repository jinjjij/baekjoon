#include <iostream>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 0;
    int T = 0;

    std::cin >> N >> T;
    //std::cout << N << ", " << T << "\n";

    int s,i,c;
    int min_time = -1;
    for(int n=0;n<N;n++){
        //std::cout << n << "th\n";
        std::cin >> s >> i >> c;
        int time = -1;
        for(int j=0;j<c;j++){
            time = s + j*i;
            //std::cout << "    " << time-T << "\n";
            if(time >= T){
                time = time - T;
                
                break;
            }
            else{
                time = -1;
            }
        }

        //std::cout << "?\n";

        if(min_time == -1 || min_time > time){
            min_time = time;
        }
    }

    std::cout << min_time;

    return 0;
}