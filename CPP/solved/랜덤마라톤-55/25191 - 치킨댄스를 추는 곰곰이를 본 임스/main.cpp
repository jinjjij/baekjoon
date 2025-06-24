#include <iostream>
#include <vector>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, A, B;
    std::cin >> N >> A >> B;

    std::cout << ((A/2+B<N)?(A/2+B):N);
    return 0;
}