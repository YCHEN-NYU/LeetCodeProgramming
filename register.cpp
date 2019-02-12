#include <iostream>
using namespace std;

int register_count(int &a){
    return ++a;
}


int main(){
    register int a;
    for (int i = 0; i < 5; i++) {
        a = register_count(a);
    }
    cout << "a (register) = " << a << endl;
}
