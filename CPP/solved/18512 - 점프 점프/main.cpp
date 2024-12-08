#include <iostream>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int x,y,p,q;
    std::cin >> p >> q >> x >> y ;

    int result = -1;
    int limit = x+y+p*q;
    while (x < limit && y < limit)
    {
        if(x<y){
            x += p;
        }else if(y<x){
            y += q;
        }else{
            result = x;
            break;
        }
    }

    std::cout << result;
    
    return 0;
}