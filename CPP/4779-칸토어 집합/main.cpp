#include <iostream>


int pow(int n, int r){
    int ret = 1;
    for(int i=0;i<r;i++){
        ret *= n;
    }

    return ret;
}


void cantore(int n){
    if(n == 0){
        std::cout << "-";
    }
    else if(n == 1){
        std::cout << "- -";
    }
    else if(n == 2){
        std::cout << "- -   - -";
    }
    else if(n == 3)  {
        std::cout << "- -   - -         - -   - -";
        return;
    }else if(n>3){
        cantore(n-1);
        for(int i=0;i<pow(3,n);i++){
            std::cout << " ";
        }
        cantore(n-1);
    }
    std::cout << "\n";

}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int input = 0;
    while(true){
        std::cin >> input;
        if(std::cin.eof())   break;
        cantore(input);
    }

    return 0;
}