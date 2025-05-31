#include <iostream>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 0;
    std::cin >> N;

    int d = 0;
    int p = 0;

    char input;
    for(int i=0;i<N;i++){
        std::cin >> input;
        if(input == 'D'){
            d++;
        }else{
            p++;
        }

        int sub = d-p>0?d-p:p-d;
        if(sub >= 2){
            break;
        }
    }


    std::cout << d << ":" << p;
    
    return 0;
}