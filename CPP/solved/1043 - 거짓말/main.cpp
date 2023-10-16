#include <iostream>
#include <set>
#include <queue>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N,M;
    std::cin >> N;
    std::cin >> M;

    
    // data[ 사람 ][ 파티 ]
    bool data[51][51] = {false};
    // 진실을 아는 사람 수
    int truth_num;
    // 진실을 아는 사람 배열 및 큐
    bool truth_arr[51];
    std::queue<int> truth_que;

    bool personVisited[51];
    // 임시 인풋
    int tmp = 0;


    // 둘째 줄 : 진실을 아는 사람 입력
    std::cin >> truth_num;

    for(int i=0;i<truth_num;i++){
        std::cin >> tmp;
        truth_arr[tmp] = true;
        truth_que.push(tmp);
        personVisited[tmp] = true;
    }


    // 셋째 줄부터 : 파티 정보 입력
    for(int i=0;i<M;i++){
        std::cin >> tmp;

        int tmp2 = 0;
        for(int j=0;j<tmp;j++){
            std::cin >> tmp2;
            data[tmp2][i] = true;
        }
    }
/*
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++){
            std::cout << data[i][j] << " ";
        }
        std::cout << "\n";
    }
*/
    // 데이터 처리
    bool isPartyTruth[51] = { false };
    
    int cur = 0;
    while(!truth_que.empty()){
        cur = truth_que.front();
        truth_que.pop();

        // cur 이 있는 파티의 구성원을 모두 다시 큐에 등록
        for(int i=0;i<M;i++){
            if(data[cur][i]){
                isPartyTruth[i] = true;

                for(int j=1;j<=N;j++){
                    if(!personVisited[j] && data[j][i]){
                        personVisited[j] = true;
                        truth_que.push(j);
                        //std::cout << "pushed : " << j << "\n";
                    }
                }
            }
        }
    }
    
    int result = M;
    for(int i=0;i<M;i++){
        if(isPartyTruth[i]){
            result --;
        }
    }

    std::cout << result << "\n";

    return 0;
}