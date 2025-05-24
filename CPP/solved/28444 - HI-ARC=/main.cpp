#include <iostream>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int a,b,c,d,e;
    std::cin >> a >> b >> c >> d >> e;

    std::cout << a*b-c*d*e;
    
    return 0;
}