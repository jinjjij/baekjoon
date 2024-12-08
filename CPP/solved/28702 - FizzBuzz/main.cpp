#include <iostream>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string str[3];
    int pos;

    for(int i=0;i<3;i++){
        std::cin >> str[i];
    }

    if(str[0] == "Fizz"){   
        if(str[1] == "Buzz"){
            pos = std::stoi(str[2]) + 1;
        }else{
            pos = std::stoi(str[1]) + 2;
        }
    }
    else if(str[0] == "Buzz"){
        if(str[1] == "Fizz"){
            pos = std::stoi(str[2]) + 1;
        }else{
            pos = std::stoi(str[1]) + 2;
        }
    }
    else if(str[0] == "FizzBuzz"){
        pos = std::stoi(str[1]) + 2;
    }
    else{
        pos = std::stoi(str[0]) + 3;
    }

    int isF = pos%3?0:1;
    int isB = pos%5?0:1;

    if(isF&&isB)    std::cout << "FizzBuzz";
    else if(isF)    std::cout << "Fizz";
    else if(isB)    std::cout << "Buzz";
    else            std::cout << pos;

    return 0;
}

//  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
//  1  2  f  4  b  f  7  8  f  b 11  f 13 14 fb 

/*



*/