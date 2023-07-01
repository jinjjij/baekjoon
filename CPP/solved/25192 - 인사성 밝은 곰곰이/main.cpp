#include <iostream>
#include <map>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::map<std::string, bool> names_map;

    int N = 0;
    std::cin >> N;

    int count = 0;

    for(int i=0;i<N;i++){
        std::string name;
        std::cin >> name;

        if(name.compare("ENTER") == 0){
            names_map.clear();
        }else if(names_map.insert(std::pair<std::string, bool> (name, true)).second){
            count ++;
        }
    }

    std::cout << count << "\n";
    return 0;
}