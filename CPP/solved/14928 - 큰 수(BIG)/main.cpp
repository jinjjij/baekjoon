#include <iostream>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    char c;
    int cur = 0;
    int input = 0;

    while( std::cin.get(c) ){
        if (c < '0' || c > '9') continue;
        input = (int)(c - '0');
        cur *= 10;
        cur += input;

        cur %= 20000303;
    }

    std::cout << cur;
    
    return 0;
}