#include <iostream>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int q = 0;
    std::cin >> q;

    long long int x;
    char updown;
    long long int range[2] = {-1000000000000000001,1000000000000000001};

    int result = 0;
    int gotit_line = 0;
    int paradox_line = 0;
    for(int i=0;i<q;i++){
        std::cin >> x >> updown;
        if(updown == '^' && range[0] < x){
            range[0] = x;
        }else if(updown == 'v' && range[1] > x){
            range[1] = x;
        }

        if(range[1] - range[0] == 2){
            result = 1;
            if(gotit_line == 0)    gotit_line = i+1;
        }else if(range[1] - range[0] < 2){
            result = 2;
            if(paradox_line == 0)    paradox_line = i+1;
        }
    }

    if(result == 0){    
        std::cout << "Hmm...";
    }else if(result == 1){
        std::cout << "I got it!\n" << gotit_line;
    }else if(result == 2){
        std::cout << "Paradox!\n" << paradox_line;
    }
    
    return 0;
}