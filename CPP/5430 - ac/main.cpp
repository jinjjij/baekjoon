#include <iostream>
#include <sstream>
#include <string>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T = 0;
    std::cin >> T;


    for(int t = 0; t<T; t++){
        std::cout << "\nloop : " << t << " : ";
        std::string p;
        std::cin >> p;

        int n;
        std::cin >> n;

        int int_arr[n];
        std::string buff_string;
        std::cin >> buff_string;
        std::cout << "\nstring : " << buff_string << "\n";

        std::stringstream ss(buff_string);
        
        int i=0;
        std::cout << "parsed int : ";
        int temp;
        while(ss >> temp){
            i++;
            std::cout << temp << " ";
        }

    }
    return 0;
}
