#include <iostream>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string input;
    int N = 0;
    std::cin >> N;
    std::cin >> input;
    std::string output = input;

    int index = 2;
    while(index < N){
        if(output[index-2] == 'P' && output[index-1] == 'S'){
            while(index < N && (output[index] == '4' || output[index] == '5')){
                N--;
                output.erase(index, 1);
            }
        }
        index++;
    }

    std::cout << output;
    
    return 0;
}