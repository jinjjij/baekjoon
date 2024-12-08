#include <iostream>



std::string GetDay2009(int d, int m){
    int day_of_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    std::string day_of_week[7] = {
        "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday"};

    int days = d;
    for(int i=1;i<m;i++){
        days += day_of_month[i];
    }
    
    return day_of_week[days%7];
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int d, m;
    std::cin >> d >> m;
    std::cout << GetDay2009(d, m);

    return 0;
}