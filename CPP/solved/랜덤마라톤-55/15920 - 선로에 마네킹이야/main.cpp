#include <iostream>
#include <vector>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 0;
    std::string input;
    std::cin >> N >> input;

    int state = 0;
    bool leverState = false;
    bool BleverFlg = false;
    for(char c : input){
        if(c == 'W')    state ++;
        else{
            if(state == 0)  leverState = !leverState;
            if(state == 1)  BleverFlg = true;
        }
    }

    int result = 0;
    if(state < 2)           result = 0;
    else if(BleverFlg)      result = 6;
    else if(leverState)     result = 1;
    else                    result = 5;

    std::cout << result;

    return 0;
}