#include <iostream>
#include <vector>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    int maxdist = 0;
    int input, prev;
    prev = 0;
    for(int i=0;i<M;i++){
        std::cin >> input;
        if(i==0){
            maxdist = input;
        }
        int newdist = input - prev;
        newdist = newdist/2 + ((newdist%2)?1:0);
        maxdist = maxdist > newdist ? maxdist : newdist;
        prev = input;
    }
    maxdist = maxdist > (N - prev) ? maxdist : (N - prev);

    std::cout << maxdist;

    return 0;
}