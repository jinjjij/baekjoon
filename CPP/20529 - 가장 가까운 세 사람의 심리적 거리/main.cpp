#include <iostream>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T = 0;
    std::cin >> T;

    int N = 0;
    bool mbti[4];
    for(int t=0;t<T;t++){
        int arr[16] = {0,};
        std::cin >> N;
        for(int i=0;i<N;i++){
            std::string s;
            std::cin >> s;
            
            int index = 0;
            if(s[0] == 'E') index += 8;
            if(s[0] == 'S') index += 4;
            if(s[0] == 'T') index += 2;
            if(s[0] == 'J') index += 1;

            arr[index] ++;
            if(arr[index]==3){
                std::cout << 0 << "\n";
                break;
            }
        }


    }
    return 0;
}