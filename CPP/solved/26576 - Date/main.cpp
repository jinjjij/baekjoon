#include <iostream>
#include <string>


std::string ChangeDateForm(std::string* origin){
    // parsing
    bool is_valid = true;

    std::string changed[3];
    size_t pos = 0;




    // change form - month
    if(origin[0] == "January")          changed[0] = "01";
    else if(origin[0] == "February")    changed[0] = "02";
    else if(origin[0] == "March")       changed[0] = "03";
    else if(origin[0] == "April")       changed[0] = "04";
    else if(origin[0] == "May")         changed[0] = "05";
    else if(origin[0] == "June")        changed[0] = "06";
    else if(origin[0] == "July")        changed[0] = "07";
    else if(origin[0] == "August")      changed[0] = "08";
    else if(origin[0] == "September")   changed[0] = "09";
    else if(origin[0] == "October")     changed[0] = "10";
    else if(origin[0] == "November")    changed[0] = "11";
    else if(origin[0] == "December")    changed[0] = "12";
    else                                is_valid = false;

    // change form - date
    int date = std::stoi(origin[1]);
    if(date > 31 || date < 1){
        is_valid = false;
    }else{
        changed[1] = (date<10?"0":"") + std::to_string(date);
    }

    // change form - year
    if(origin[2].size() == 1){
        changed[2] = "0" + origin[2];
    }else if(origin[2].size() == 2){
        changed[2] = origin[2];
    }else{
        changed[2] = origin[2].substr(origin[2].size()-2);
    }
    

    // make output string
    std::string output;
    if(is_valid){
        output = changed[0] + "/" + changed[1] + "/" + changed[2];
    }else{
        output = "Invalid";
    }

    return output;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n = 0;
    std::cin >> n;


    for(int i=0;i<n;i++){
        std::string buffer[3];
        std::cin >> buffer[0] >> buffer[1] >> buffer[2];
        std::cout << ChangeDateForm(buffer) << "\n";
    }

    return 0;
}