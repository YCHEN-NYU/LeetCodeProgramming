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

int main(){
    vector<int> preorderList = {3, 9, 20, 15, 7}, inorderList = {9, 3, 15, 20, 7};
    
}
