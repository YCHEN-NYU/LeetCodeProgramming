#include <iostream>
#include <queue>
#include <queue>
#include <vector>
using namespace std;

queue<int> initQueue(vector<int> &nums){
    queue<int> Q;
    for (int i = 0; i < nums.size(); i++) {
        Q.push(nums[i]);
    }
    return Q;
}

void printQueue(queue<int> &Q){
    while(!Q.empty()){
        cout << Q.front();
        Q.pop();
        if(!Q.empty())  cout << ", ";
    }   cout << endl;
}

deque<int> initDeque(vector<int> &nums){
    deque<int> dQ;
    for (int i = 0; i < nums.size(); i++) {
        dQ.push_front(nums[i]);
    }
    return dQ;
}

void printDeque(deque<int> &dQ){
    while(!dQ.empty()){
        cout << dQ.back();
        dQ.pop_back();
        if(!dQ.empty()) cout << ", ";
    }   cout << endl;
}



int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    queue<int> Q = initQueue(nums);
    printQueue(Q);
    
    deque<int> dQ = initDeque(nums);
    printDeque(dQ);
    return 0;
}
