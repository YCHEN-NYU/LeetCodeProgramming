/*
 题目：学习使用auto定义变量的用法
 */
#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, char> int2char_map = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
    for(auto it = int2char_map.begin(); it != int2char_map.end(); it++){
        cout << it->first << ": " << it->second << endl;
    }
    
}
