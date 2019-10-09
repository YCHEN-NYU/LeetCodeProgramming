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

TreeNode * helper(vector<int> &preorder, vector<int> &inorder, int preStart, int inStart, int inEnd){
    if(preStart > preorder.size() - 1 || inStart > inEnd){
        return NULL;
    }
    
    TreeNode * root = new TreeNode(preorder[preStart]);
    int inIndex = 0;
    for(int i = inStart; i <= inEnd; i++){
        if(inorder[i] == root->val){
            inIndex = i;
        }
    }
    root->left = helper(preorder, inorder, preStart + 1, inStart, inIndex - 1);
    root->right = helper(preorder, inorder, preStart + inIndex - inStart + 1, inIndex + 1, inEnd);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return helper(preorder, inorder, 0, 0, inorder.size() - 1);
}



int main(){
    vector<int> preorderList = {3, 9, 20, 15, 7}, inorderList = {9, 3, 15, 20, 7};
    TreeNode * root = buildTree(preorderList, inorderList);
    printInorder(root);
    cout << endl;
}
