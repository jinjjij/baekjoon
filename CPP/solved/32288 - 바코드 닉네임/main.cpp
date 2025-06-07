#include <iostream>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 0;
    std::cin >> N;
    std::string str;
    std::cin >> str;

    for(int i=0;i<N;i++){
        if(str[i] == 'l')   str[i] = 'L';
        if(str[i] == 'I')   str[i] = 'i';
    }

    std::cout << str;
    
    return 0;
}