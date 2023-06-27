#include <iostream>
#include <map>


int main(){
    int N = 0;
    std::cin >> N;
    
    std::map<std::string, bool> name_map;      // < name , is_present >
    std::map<std::string, bool>::reverse_iterator iter;

    std::string name;
    std::string act;

    for(int i=0;i<N;i++){
        std::cin >> name >> act;
        std::cout << i+1 << " : " << name << " " << act << std::endl;

        if(act.compare("enter") == 0){
            if(name_map.count(name) == 0){
                name_map.insert(std::make_pair(name, true));
            }

        }else if(act.compare("leave") == 0){
            if(name_map.count(name) == 1){
                name_map.erase(name);
            }
        }else{
            std::cout << "error in input stream!" << std::endl;
        }
    }

    

    for(auto iter:name_map){
        std::cout << iter.first << std::endl;
    }
    return 0;
}