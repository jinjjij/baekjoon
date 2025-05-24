#include <iostream>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int base[5] = {1,2,6,24,120};

    int input = 0;
    while(true){
        std::cin >> input;
        if(input == 0){
            break;
        }

        int digit[5];
        digit[0] = input%10;
        digit[1] = (input%100)/10;
        digit[2] = (input%1000)/100;
        digit[3] = (input%10000)/1000;
        digit[4] = input/10000;

        int output = 0;
        for(int i=0;i<5;i++){
            output += digit[i] * base[i];
        }

        std::cout << output << '\n';
    }
    
    return 0;
}