#include <iostream>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int prime[9] = {2, 3, 5,  7,   11,   13,    17,     19,      23};
    int basis[9] = {2, 6, 30, 210, 2310, 30030, 510510, 9699690, 223092870};
    std::string basis_string[9] = {"2", "2*3", "2*3*5", "2*3*5*7", "2*3*5*7*11", 
    "2*3*5*7*11*13", "2*3*5*7*11*13*17", "2*3*5*7*11*13*17*19", "2*3*5*7*11*13*17*19*23"};
    
    int n = 0;
    while(1){
        std::cin >> n;
        if(n==0)    break;
        int output[9] = {0,};
        std::string outputstring = std::to_string(n) + " = ";

        for(int i=8;i>=0;i--){
            if(n>=basis[i]){
                output[i] = n/basis[i];
                n = n%basis[i];
            }
        }

        
        if(n){
            outputstring += "1";
        }
        bool is_first = true;
        for(int i=0;i<9;i++){
            if(output[i]){
                if(!(is_first&&n==0)){
                    outputstring += " + ";
                }
                is_first = false;
                outputstring += std::to_string(output[i]) + "*" + basis_string[i];
            }
        }
        outputstring += "\n";

        std::cout << outputstring;
    }
    return 0;
}