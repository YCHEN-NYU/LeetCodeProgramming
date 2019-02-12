/*
题目：请输入星期几的第一个字母来判断一下是星期几，如果第一个字母一样，
则继续判断第二个字母。
*/
// [M]onday, [W]ednesday, [F]riday, [Tu]esday,
// [Th]ursday, [Sa]turday, [Su]nday
#include <iostream>
#include <string>
#include <iomanip>
#include <set>

using namespace std;

char enter_first_character(){
    char c;
    set<char> char_set;
    char_set = {'M', 'T', 'W', 'F', 'S'};
    do{
        cout << "Enter a character from {'M', 'T', 'W', 'F', 'S'}: ";
        cin >> c;
    } while(char_set.find(c) == char_set.end());
    return c;
}

char enter_second_character(){
    char c;
    set<char> char_set;
    char_set = {'u', 'h', 'a'};
    do{
        cout << "Enter a character from {'u', 'h', 'a'}: ";
        cin >> c;
    } while(char_set.find(c) == char_set.end());
    return c;
}


int index_day_of_week(){
    char c1 = enter_first_character();
    
    switch(c1){
        case 'M': return 0; break;
        case 'W': return 2; break;
        case 'F': return 4; break;
        case 'T':{
            char c2 = enter_second_character();
            if(c2 == 'a')  return index_day_of_week();
            switch(c2){
                case 'u': return 1;
                case 'h': return 3;
            }
        }; break;
        case 'S':{
            char c2 = enter_second_character();
            if(c2 == 'h') return index_day_of_week();
            switch(c2){
                case 'a': return 5; break;
                case 'u': return 6; break;
            }
        };
    }
    
    return -1;
}

int main() {

    int day = index_day_of_week();
    string day_of_week[] = {"Monday", "Tuesday", "Wednesday", "Thursday",
                            "Friday", "Saturday", "Sunday"};
    cout << "Day of week: " << day_of_week[day] << endl;
    return 0;
}
