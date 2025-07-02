#include <iostream>
#include <vector>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int load, unload;
    int max = 0;
    int cur = 0;
    for(int i=0;i<10;i++){
        std::cin >> unload >> load;
        cur += load - unload;
        if(cur < 0) cur = 0;
        if(cur > 10000) cur = 10000;

        max = max>cur ? max : cur;
    }

    std::cout << max;

    return 0;
}