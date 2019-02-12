#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> stk;
    
    for(int i = 10; i > 0; i--){
        stk.push(i);
    }
    
    cout << stk.size() << endl;
    stk.pop();
    cout << "stk.top() = " << stk.top() << endl;
    stk.push(-1);
    cout << "stk.top() = " << stk.top() << endl;
    
    
    
    return 0;
}
