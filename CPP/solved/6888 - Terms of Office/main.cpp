#include <iostream>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int x,y;
    std::cin >> x >> y;

    while(x<=y){
        std::cout << "All positions change in year " << x << "\n";
        x += 60;
    }
    
    return 0;
}