/*
 The set [1,2,3,...,n] contains a total of n! unique permutations.
 By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
 
 "123"
 "132"
 "213"
 "231"
 "312"
 "321"
 
 Given n and k, return the kth permutation sequence.
 Note:
 Given n will be between 1 and 9 inclusive.
 Given k will be between 1 and n! inclusive.
 
 Example 1:
 Input: n = 3, k = 3
 Output: "213"
 
 Example 2:
 Input: n = 4, k = 9
 Output: "2314"
 */

#include <iostream>
#include <vector>
using namespace std;


public String getPermutation(int n, int k) {
    List<Integer> num = new LinkedList<Integer>();
    for (int i = 1; i <= n; i++) num.add(i);
    int[] fact = new int[n];  // factorial
    fact[0] = 1;
    for (int i = 1; i < n; i++) fact[i] = i*fact[i-1];
    k = k-1;
    StringBuilder sb = new StringBuilder();
    for (int i = n; i > 0; i--){
        int ind = k/fact[i-1];
        k = k%fact[i-1];
        sb.append(num.get(ind));
        num.remove(ind);
    }
    return sb.toString();
}


int main(){
    
}

