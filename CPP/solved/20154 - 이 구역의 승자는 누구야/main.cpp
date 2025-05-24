#include <iostream>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int arr[26] = {3, 2, 1, 2, 3, 3, 3, 3, 1, 1, 3, 1, 3, 3, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1};
    std::string s;
    std::cin >> s;

    int sum = 0;
    for(int i=0;i<s.length();i++){
        sum += arr[s[i] - 'A'];
    }

    if(sum%2 == 0){
        std::cout << "You're the winner?";
    }else{
        std::cout << "I'm a winner!";
    }

    
    return 0;
}