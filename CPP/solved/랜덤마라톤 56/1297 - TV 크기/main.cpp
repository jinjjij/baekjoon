#include <iostream>
#include <vector>
#include <cmath>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    double D, H, W;
    std::cin >> D >> H >> W;

    double a = sqrt(D*D/(H*H+W*W));

    std::cout << (int)(H*a) << " " << (int)(W*a);

    return 0;
}