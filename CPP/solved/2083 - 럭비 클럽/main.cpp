#include <iostream>
#include <vector>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string name;
    int age, weight;
    while(true){
        std::cin >> name >> age >> weight;
        if(name == "#" && age == 0 && weight == 0)  break;

        std::cout << name;
        if(age>17 || weight >= 80)  std::cout << " Senior\n";
        else    std::cout << " Junior\n";
    }

    return 0;
}