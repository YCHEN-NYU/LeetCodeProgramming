
#include <iostream>
#include "external_main.c"
using namespace std;

// use of extern keyword
int main() {
    int a;
    a += 1;
    int b;
    b += 2;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    return 0;
}


