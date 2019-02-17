#include <iostream>
using namespace std;
#define MAX 1000

// implement stack using array
class Stack{
public:
    int top;
    
public:
    int data;
    int a[MAX];
    int pop();
    Stack() {top = -1;}
    bool push(int x);
    bool isEmpty();
};

bool Stack::push(int x){
    if(top >= (MAX - 1)){
        cout << "Stack Overflow" << endl;
        return false;
    }
    else{
        top++;
        a[top] = x;
        cout << x << " pushed into stack" << endl;
        return true;
    }
}

int Stack::pop(){
    if(top < 0){
        cout << "Stack Underflow" << endl;
        return 0;
    }
    else{
        int x = a[top];
        top--;
        return x;
    }
}

bool Stack::isEmpty(){
    return (top < 0);
}

// implement stack using linked list


int main(){
    
    class Stack s;
    s.push(1);
    s.push(2);
    cout << s.pop() << " popped from stack" << endl;
    return 0;
}
