#include <iostream>
using namespace std;

void fun(){
    static int count = 0;
    ++count;
    cout << "count = " << count << endl;
}


int main() {
    for(int i = 0; i < 5; i++)  fun();
    
    return 0;
}
