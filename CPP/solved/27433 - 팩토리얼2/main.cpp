#include <iostream>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    std::cin >> n;

    long long int output = 1;
    for(int i=0; i<n; i++){
        output *= i+1;
    }

    std::cout << output;
    
    return 0;
}