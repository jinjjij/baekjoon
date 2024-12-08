#include <iostream>
#include <string>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string str = "1223asdfasdfa2133";

    std::cout << std::stoi(str);
    return 0;
}