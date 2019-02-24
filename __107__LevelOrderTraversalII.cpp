/*
 107. Binary Tree Level Order Traversal II
 Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 
 For example:
 Given binary tree [3,9,20,null,null,15,7],
 3
 / \
 9  20
 /  \
 15   7
 return its bottom-up level order traversal as:
 [
 [15,7],
 [9,20],
 [3]
 ]
 */
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode * left, * right;
    TreeNode(int val): val(val), left(NULL), right(NULL) {}
};

void printInorder(TreeNode *root){
    if(!root)   return;
    else{
        if(root->left)  printInorder(root->left);
        cout << root->val << ", ";
        if(root->right) printInorder(root->right);
    }
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    if(!root)   return res;
    queue<TreeNode*> Q;
    Q.push(root);
    
    while(!Q.empty()){
        int len = Q.size();
        vector<int> tmp;
        for(int i = 0; i < len; i++){
            TreeNode * newNode = Q.front();
            Q.pop();
            tmp.push_back(newNode->val);
            if(newNode->left)   Q.push(newNode->left);
            if(newNode->right)  Q.push(newNode->right);
        }
        res.insert(res.begin(), tmp);
    }
    return res;
}
