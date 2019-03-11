/*
 621. Task Scheduler
 Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.
 However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.
 You need to return the least number of intervals the CPU will take to finish all the given tasks.
 
 Example:
 
 Input: tasks = ["A","A","A","B","B","B"], n = 2
 Output: 8
 Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.

 Note:
 The number of tasks is in the range [1, 10000].
 The integer n is in the range [0, 100].
 */
#include <iostream>
#include <vector>
#include "printMatrix1D.h"
using namespace std;

int leastIntervals(vector<char> &tasks, int n){
    // count the frequency of 'A' to 'Z' characters
    vector<int> cnt(26, 0);
    for(auto c : tasks){
        cnt[c - 'A']++;
    }
    // sort from higher frequency to lower frequncy
    sort(cnt.begin(), cnt.end(), [](int a, int b){return a > b;});
    // printMatrix1D(cnt);
    int res = (cnt[0] - 1)*(n + 1);
    for(int i = 0; i < cnt.size(); i++){
        if(cnt[i] == cnt[0]) res++; // add 1 to due to the last group
    }
    if(res < tasks.size())
        return tasks.size();
    else
        return res;
}

int main(){
    vector<char> tasks = {'B', 'B', 'C', 'A', 'A', 'A',};
    cout << leastIntervals(tasks, 2) << endl;
}
