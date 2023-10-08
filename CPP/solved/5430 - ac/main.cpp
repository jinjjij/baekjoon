#include <iostream>
#include <string>
#include <sstream>
#include <deque>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T = 0;
    std::cin >> T;


    for(int t=0;t<T;t++){
        std::string p;
        std::cin >> p;
        int n = 0;
        std::cin >> n;
/*
        std::stringstream sstream(p);
        std::string word;

        
        int data;

        while(getline(sstream, word, ',')){
            data = stoi(word);
        }
*/
        char tempBuff;
        int tempInt;
        std::deque<int> mydeque;
        std::deque<int>::iterator iter;
        std::deque<int>::reverse_iterator riter;

        std::cin >> tempBuff;
        for(int i=0;i<n;i++){
            std::cin >> tempInt;
            mydeque.push_back(tempInt);
            std::cin >> tempBuff;
        }
        if(n==0){
            std::cin >> tempBuff;
        }

        bool isFront = true;
        bool isError = false;

        for(int pIndex = 0;pIndex < p.length(); pIndex++){
            char inst = p[pIndex];
            if(inst == 'R'){
                isFront = !isFront;
            }else if(inst == 'D'){
                if(mydeque.empty()){
                    isError = true;
                    break;
                }
                if(isFront){
                    //std::cout << "(t=" << t << ", " << isFront << ") deleted : " << mydeque.front() << "\n";
                    mydeque.pop_front();
                }else{
                    //std::cout << "(t=" << t << ", " << isFront << ") deleted : " << mydeque.back() << "\n";
                    mydeque.pop_back();
                }
            }
        }

        if(isError){
            std::cout << "error\n";
        }else{
            std::cout << "[";
            if(isFront){
                for(iter = mydeque.begin(); iter != mydeque.end(); iter++){
                    if(iter != mydeque.begin()) std::cout << ",";
                    std::cout << *iter;
                }
            }else{
                for(riter = mydeque.rbegin(); riter != mydeque.rend(); riter++){
                    if(riter != mydeque.rbegin()) std::cout << ",";
                    std::cout << *riter;
                }
            }
            
            std::cout << "]\n";
        }

    }
    return 0;
}
