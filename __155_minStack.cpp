/* 
155. Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

#include <iostream>
#include <stack>
using namespace std;

class minStack{
private:
	stack<int> s1, s2;
public:
	void push(int element){
		s1.push(element);
		if(s2.empty() || element < s2.top())
			s2.push(element);
	}

	int pop(){
		if(!s1.empty()){
			if(s1.top() == s2.top()){
				s1.pop();
				s2.pop();
			}
			else
				s1.pop();
		}
	}

	int getMin(){
		return s2.top();
	}
}


int main(){

}











