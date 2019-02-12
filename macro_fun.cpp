#include <iostream>
using namespace std;

#define MAXIMUM( a, b ) a > b ? a : b

int main(){
    int c = MAXIMUM(1, 2);
    cout << "c = " << c << endl;
    return 0;
}
