/*
 96. Unique Binary Search Trees
 Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
 
 Example:
 
 Input: 3
 Output: 5
 Explanation:
 Given n = 3, there are a total of 5 unique BST's:
 
 1         3     3      2      1
 \       /     /      / \      \
 3     2     1      1   3      2
 /     /       \                 \
 2     1         2                 3
 */

 
 int numTrees(int n) {
     // root k, root->left = [1, 2, ..., k - 1], root->right = [k + 1, k + 2, ..., n]
     if(n < 0)   return 0;
     if(n <= 0)   return 1;
 
    vector<int> num(n + 1, 0);
     num[0] = 1;
     num[1] = 1;
     // fibonacci-like
     for(int i = 2; i <= n; i++){
         for(int j = 1; j <= i; j++){
             num[i] += num[j - 1]*num[i - j];
         }
     }
     return num[n];
 }
 
