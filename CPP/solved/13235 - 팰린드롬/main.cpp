#include <iostream>


bool isPalindrom(std::string str){
    int size = str.size();
    
    for(int i=0;i<size/2;i++){
        if(str[i] != str[size-i-1]) return false;
    }

    return true;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string input;
    std::cin >> input;
    std::cout << (isPalindrom(input)?"true":"false");
    
    return 0;
}