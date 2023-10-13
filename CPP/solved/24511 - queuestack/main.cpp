#include <iostream>
#include <deque>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N = 0;
    std::cin >> N;

    std::deque<int> mydeque;
    int mask[N];

    for(int i=0;i<N;i++){
        std::cin >> mask[i];
    }

    int tempInput = 0;
    for(int i=0;i<N;i++){
        std::cin >> tempInput;

        if(!mask[i]){
            mydeque.push_front(tempInput);
        }
    }

    int M = 0;
    std::cin >> M;

    for(int i=0;i<M;i++){
        std::cin >> tempInput;
        mydeque.push_back(tempInput);
        std::cout << mydeque.front() << " ";
        mydeque.pop_front();
    }

    return 0;
}

/*
q s s q
1 2 3 4 

2삽입
2 

*/