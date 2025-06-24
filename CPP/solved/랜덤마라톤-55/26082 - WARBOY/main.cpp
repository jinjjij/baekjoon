#include <iostream>
#include <vector>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int A, B, C;
    std::cin >> A >> B >> C;
    std::cout << 3*C*B/A;
    return 0;
}