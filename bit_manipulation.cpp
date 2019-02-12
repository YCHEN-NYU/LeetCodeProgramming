/*
 学习使用按位取反~。
*/

#include <iostream>
#include <bitset>
#include <iomanip>
using namespace std;

int main() {
    cout << "0 & 1 = " << (0 & 1) << endl;
    cout << "0 | 1 = " << (0 | 1) << endl;
    cout << "0 ^ 1 = " << (0 ^ 1) << endl;
    
    cout << "1 << 1 = " << (1 << 1) << endl;
    cout << "2 >> 1 = " << (2 >> 1) << endl;
    cout << "8 << 2 = " << (8 << 2) << endl;
    
    cout << setw(32) << "bitset<4>(~0) = " << setw(16) << bitset<4>(~0) << endl;
    cout << setw(32) << "bitset<8>(~0) = " << setw(16) << bitset<8>(~0) << endl;
    cout << setw(32) << "bitset<16>(~0) = " << setw(16) << bitset<16>(~0) << endl;
    
    return 0;
}
