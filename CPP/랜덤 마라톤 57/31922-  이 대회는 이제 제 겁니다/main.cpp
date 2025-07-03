#include <iostream>
#include <vector>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int a,p,c;
    std::cin>>a>>p>>c;
    std::cout << std::max(a+c,p);
    
    return 0;
}