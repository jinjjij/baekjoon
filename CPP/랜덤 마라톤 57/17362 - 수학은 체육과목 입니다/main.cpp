#include <iostream>
#include <vector>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    std::cin >> n;
    int a[8] = {2,1,2,3,4,5,4,3};
    std::cout << a[n%8];

    return 0;
}