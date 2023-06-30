#include <iostream>
#include <map>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 0;
    std::cin >> N;
    
    std::map<std::string, bool> name_map;      // < name , is_present >
    std::map<std::string, bool>::reverse_iterator name_map_iter;

    std::string name;
    std::string act;

    for(int i=0;i<N;i++){
        std::cin >> name >> act;
        //std::cout << i+1 << " : " << name << " " << act << std::endl;

        if(act.compare("enter") == 0){
            name_map.insert(std::make_pair(name, true));
        }else if(act.compare("leave") == 0){
            name_map.erase(name);
        }else{
            std::cout << "error in input stream!\n";
        }
    }

    

    for(name_map_iter = name_map.rbegin(); name_map_iter != name_map.rend(); name_map_iter++){
        std::cout << (*name_map_iter).first << "\n";
    }
    return 0;
}