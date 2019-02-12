#include <iostream>
using namespace std;



int main() {
    
    for (int i = 110; i < 120; i++) {
        cout << "[" << i/100 << " "
             << (i - (i/100)*100)/10 << " "
             << i%10 << "]" << endl;
    }
    return 0;
}
