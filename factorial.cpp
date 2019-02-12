#include <iostream>
#include <vector>
using namespace std;

long long factorial(int n){
    if(n == 0 || n == 1)    return 1;
    vector<long long> res(n, 1);
    for(int i = 2; i <= n; i++){
        res[i] = res[i - 1]*i;
    }
    return res[n];
}

int main() {
    cout << factorial(10) << endl;
    return 0;
}
