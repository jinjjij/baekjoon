#include <iostream>
#include <deque>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 0;
    std::cin >> N;

    std::deque<int> mydeque;

    int inst = 0;
    int x = 0;
    for(int i=0;i<N;i++){
        std::cin >> inst;
        switch(inst){
            case 1: // insert x in front of the deque
                std::cin >> x;
                mydeque.push_front(x);
                break;
            case 2: // insert x in the back of the deque
                std::cin >> x;
                mydeque.push_back(x);
                break;
            case 3:
                if(mydeque.empty()){
                    std::cout << -1 << '\n';
                }else{
                    std::cout << mydeque.front() << '\n';
                    mydeque.pop_front();
                }
                break;
            case 4:
                if(mydeque.empty()){
                    std::cout << -1 << '\n';
                }else{
                    std::cout << mydeque.back() << '\n';
                    mydeque.pop_back();
                }
                break;
            case 5:
                std::cout << mydeque.size() << '\n';
                break;
            case 6:
                if(mydeque.empty()){
                    std::cout << 1 << '\n';
                }else{
                    std::cout << 0 << '\n';
                }
                break;
            case 7:
                if(mydeque.empty()){
                    std::cout << -1 << '\n';
                }else{
                    std::cout << mydeque.front() << '\n';
                }
                break;
            case 8:
                if(mydeque.empty()){
                    std::cout << -1 << '\n';
                }else{
                    std::cout << mydeque.back() << '\n';
                }
                break;
        }
    }

    return 0;
}