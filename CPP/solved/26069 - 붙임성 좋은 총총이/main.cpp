#include <iostream>
#include <map>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::map<std::string , bool> names_map;
    int N = 0;
    std::cin >> N;

    std::string name[2];
    int count = 1;

    for(int i=0;i<N;i++){
        std::cin >> name[0] >> name[1];

        
        for(int l=0;l<2;l++){
            if(name[l].compare("ChongChong")){
                names_map.insert(std::pair<std::string, bool>(name[l],false));
            }else{
                names_map.insert(std::pair<std::string, bool>(name[l],true));
            }
        }


        bool* rainbow1 = &(names_map.find(name[0])->second);
        bool* rainbow2 = &(names_map.find(name[1])->second);

        if(*rainbow1 != *rainbow2){
            *rainbow1 = true;
            *rainbow2 = true;

            count ++;
        }
    }

    std::cout << count << "\n";
    return 0;
}