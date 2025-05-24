#include <iostream>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 0;
    std::cin >> N;

    std::string buffer;
    std::getline(std::cin , buffer);
    for(int i=0;i<N;i++){
        std::getline(std::cin , buffer);
        std::cout << i+1 << ". " << buffer << "\n";
    }
    
    return 0;
}