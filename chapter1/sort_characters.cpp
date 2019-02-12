#include <iostream>
using namespace std;

bool cmp_descend(int i, int j) {return i > j;}

struct myclass{
    bool operator() (int i,int j) { return (i < j);}
} myobject;

int main() {
    string s = "cdab";
    cout << s << endl;
    // default cmp <
    std::sort(s.begin(), s.end());
    cout << s << endl;
    
    // cmp >
    std::sort(s.begin(), s.end(), cmp_descend);
    cout << s << endl;
    
    // cmp >
    std::sort(s.begin(), s.end(), myobject);
    cout << s << endl;
}
