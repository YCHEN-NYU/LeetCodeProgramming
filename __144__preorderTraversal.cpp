/*
 144. Binary Tree Preorder Traversal
 Given a binary tree, return the preorder traversal of its nodes' values.
 
 Example:
 
 Input: [1,null,2,3]
 1
  \
  2
 /
3
 
 Output: [1,2,3]
 Follow up: Recursive solution is trivial, could you do it iteratively?
 */

vector<int> preorderTraversal(TreeNode* root) {
    if(!root) return vector<int>();
    vector<int> res;
    
    stack<TreeNode *> stk;
    stk.push(root);
    
    while(!stk.empty()){
        TreeNode * cur = stk.top();
        res.push_back(cur->val);
        stk.pop();
        if(cur->right)  stk.push(cur->right);
        if(cur->left) stk.push(cur->left);
    }
    
    return res;
}
