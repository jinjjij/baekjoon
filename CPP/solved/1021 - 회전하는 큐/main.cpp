#include <iostream>
#include <deque>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::cin >> N >> M;
    std::deque<int> deque;

    for(int i=0;i<N;i++){
        deque.push_back(i+1);
    }

    int input;
    int count = 0;
    for(int i=0;i<M; i++){
        std::cin >> input;

        int targetIndex;
        for(int i=0;i<deque.size();i++){
            if(deque[i] == input){
                targetIndex = i;
                break;
            }
        }

        
        while(deque.front() != input){
            if(targetIndex < deque.size()/2+1){
                int cur = deque.front();
                deque.pop_front();
                deque.push_back(cur);
            }else{
                int cur = deque.back();
                deque.pop_back();
                deque.push_front(cur);
            }   
            count++;
        }

        deque.pop_front();
    }

    std::cout << count;
    
    return 0;
}
