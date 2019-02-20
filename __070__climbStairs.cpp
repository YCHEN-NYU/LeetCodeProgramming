/*
 70. Climbing Stairs
 You are climbing a stair case. It takes n steps to reach to the top.
 Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 Note: Given n will be a positive integer.
 */
#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n) {
    if(n == 1)  return 1;
    if(n == 2)  return 2;

    vector<int> steps(n, 0);
    steps[0] = 1; // 1 step
    steps[1] = 2; // 2 steps
    for(int i = 2; i < n; i++){
        steps[i] = steps[i - 1] + steps[i - 2];
        // cout << "i = " << i << endl;
    }

    return steps[n - 1];
}

//int climbStairs(int n){
//    vector<int> distinctWays(n, 0);
//    distinctWays[0] = 1; // 1 step
//    distinctWays[1] = 2; // 2 steps
//    
//    for(int i = 2; i < n; i++){
//        distinctWays[i] = distinctWays[i - 1] + distinctWays[i - 2];
//    }
//    return distinctWays[n - 1];
//}



int main(){
    int n = 10;
    int totalWays = climbStairs(n);
    cout << "totalWays[" << n << "] = " << totalWays << endl;
}




