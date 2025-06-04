#include <iostream>
#include <iomanip>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    float d1, d2;
    std::cin >> d1 >> d2;
    const float pi = 3.141592;

    std::cout << std::fixed << std::setprecision(6) << d1*2 + d2*2*pi;
    
    return 0;
}