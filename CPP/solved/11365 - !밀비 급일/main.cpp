#include <iostream>
#include <string>
#include <algorithm>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string buffer;
    while(true){
        std::getline(std::cin , buffer);
        if(buffer == "END"){
            break;
        }

        std::reverse(buffer.begin(), buffer.end());
        std::cout << buffer << std::endl;
    }
    
    
    return 0;
}