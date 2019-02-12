#include <iostream>
#include <iomanip>
using namespace std;

bool is_alpha(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool is_digit(char c){
    return (c >= '0' && c <= '9');
}

int main(){
    cout << "enter a character c = ";
    char c = getchar();
    
    cout << "is_alpha(c)? " << boolalpha << is_alpha(c) << endl;
    cout << "isalpha(c)? " << boolalpha << isalpha(c) << endl;
    cout << "is_digit(c)? " << boolalpha << is_digit(c) << endl;
    cout << "isdigit(c)? " << boolalpha << isdigit(c) << endl;
    return 0;
}


