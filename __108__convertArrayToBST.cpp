#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode * left, * right;
    TreeNode(int val): val(val), left(NULL), right(NULL) {}
};

void printInorder(TreeNode * root){
    if(!root)   return;
    else{
        if(root->left)  printInorder(root->left);
        cout << root->val << ", ";
        if(root->right) printInorder(root->right);
    }
}

TreeNode * helper(vector<int> & nums, int low, int high){
    if(low > high){
        return NULL;
    }
    else{
        int mid = (low + high)/2;
        TreeNode * newNode = new TreeNode(nums[mid]);
        if(newNode) newNode->left = helper(nums, low, mid - 1);
        if(newNode) newNode->right = helper(nums, mid + 1, high);
        return newNode;
    }
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    if(nums.size() == 0) return NULL;
    return helper(nums, 0, nums.size() - 1);
}


int main(){
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode * root = sortedArrayToBST(nums);
    printInorder(root);
    cout << endl;
    return 0;
}
