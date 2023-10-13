#include <iostream>
#include <string>
#include <queue>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::queue<int> q;
    int N = 0;

    std::cin >> N;

    std::string inst;
    int x = 0;

    for(int i=0;i<N;i++){
        std::cin >> inst;
        
        if(inst == "push"){
            std::cin >> x;
            q.push(x);
        }else if(inst == "pop"){
            if(q.empty()){
                std::cout << -1 << '\n';
            }else{
                std::cout << q.front() << '\n';
                q.pop();
            }
        }else if(inst == "size"){
            std::cout << q.size() << '\n';
        }else if(inst == "empty"){
            std::cout << q.empty()? 1 : 0;
            std::cout << '\n';
        }else if(inst == "front"){
            if(q.empty()){
                std::cout << -1 << '\n';
            }else{
                std::cout << q.front() << '\n';
            }
        }else if(inst == "back"){
            if(q.empty()){
                std::cout << -1 << '\n';
            }else{
                std::cout << q.back() << '\n';
            }
        }else{
            //error
        }
    }

    
    return 0;
}