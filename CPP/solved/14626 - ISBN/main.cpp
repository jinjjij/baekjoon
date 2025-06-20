#include <iostream>
#include <vector>


bool isValid(std::string query){
    int checkSum = 0;
    for(int i=0;i<13;i++){
        checkSum += (query[i]-'0') * (i%2?3:1);
    }
    return (checkSum%10==0);
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string input;
    std::cin >> input;

    int starIndex = 0;
    for(int i=0;i<13;i++){
        if(input[i] == '*'){
            starIndex = i;
            break;
        }
    }

    for(int i=0;i<10;i++){
        input[starIndex] = i+'0';
        if(isValid(input)){
            std::cout << i;
            break;
        }
    }
    
    
    return 0;
}