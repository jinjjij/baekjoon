#include <iostream>
#include <vector>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int x,y;
    int X = 0;
    int Y = 0;

    std::cin >> x >> y;

    for(int i=0;i<x;i++){
        X = X*10+1;
    }

    for(int i=0;i<y;i++){
        Y = Y*10+1;
    }

    std::cout << X+Y;

    return 0;
}