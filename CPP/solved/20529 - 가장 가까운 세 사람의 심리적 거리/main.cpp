#include <iostream>



int getDist(int a, int b){
    return (a/8 != b/8) + ((a%8)/4 != (b%8)/4) + ((a%4)/2 != (b%4)/2) + (a%2 != b%2);
}


int min(int a,int b){
    return a<b?a:b;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T = 0;
    std::cin >> T;

    int N = 0;
    for(int t=0;t<T;t++){
        bool endFlag = false;
        int arr[16] = {0,};
        int input[40] = {0,};
        int inputSize = 0;
        int ret = 1000;

        std::cin >> N;
        for(int i=0;i<N;i++){
            std::string s;
            std::cin >> s;

            if(endFlag) continue;
            
            int index = 0;
            if(s[0] == 'E') index += 8;
            if(s[1] == 'S') index += 4;
            if(s[2] == 'T') index += 2;
            if(s[3] == 'J') index += 1;

            arr[index] ++;
            input[inputSize++] = index;
            if(arr[index]==3){
                ret = 0;
                endFlag = true;
            }
        }

        
        if(!endFlag) {
        for(int i=0;i<inputSize-2;i++){
            for(int j=i+1;j<inputSize-1;j++){
                for(int k=j+1;k<inputSize;k++){
                    ret = min(ret, getDist(input[i], input[j]) + getDist(input[j], input[k]) + getDist(input[i], input[k]));
                }
            }
        }}

        std::cout << ret << "\n";

    }
    return 0;
}