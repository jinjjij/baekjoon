#include <iostream>


int pow(int base, int exponent){
    int ret = 1;
    for(int i=0;i<exponent;i++){
        ret *= base;
    }

    return ret;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n = 0;
    std::cin >> n;

    int pow_8[8], pow_10[8], pow_16[8];

    // pow init
    for(int i=0;i<8;i++){
        pow_8[i] = pow(8,i);
        pow_10[i] = pow(10,i);
        pow_16[i] = pow(16,i);
    }

    for(int i=0;i<n;i++){
        int num, input;
        std::cin >> num >> input;
        int digit[7] = {0,};
        bool isOctalPosiible = true;

        for(int i=0;i<7;i++){
            digit[i] = (input%pow_10[i+1])/pow_10[i];
            if(digit[i] > 7){
                isOctalPosiible = false;
            }
        }

    

        int Octal = 0;
        int Decimal = 0;
        for(int i=0;i<7;i++){
            Octal += digit[i] * pow_8[i];
            Decimal += digit[i] * pow_16[i];
        }
        if(!isOctalPosiible)    Octal = 0;



        std::cout << num << " " << Octal << " " << input << " " << Decimal << "\n";
    }
    
    return 0;
}



