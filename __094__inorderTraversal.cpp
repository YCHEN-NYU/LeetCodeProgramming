/*
 94. Binary Tree Inorder Traversal
 Given a binary tree, return the inorder traversal of its nodes' values.
 
 Example:
 Input: [1,null,2,3]
1
 \
  2
 /
3
 
 Output: [1,3,2]
 Follow up: Recursive solution is trivial, could you do it iteratively?
 */

// recursive
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    dfs(root, res);
    return res;
}

void dfs(TreeNode * root, vector<int> &res){
    if(!root) return;
    else{
        if(root->left) dfs(root->left, res);
        res.push_back(root->val);
        if(root->right) dfs(root->right, res);
    }
}


// Iterative
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    if(!root) return res;
    stack<TreeNode *> stk;
    TreeNode * cur = root;
    while(!stk.empty() || cur){
        if(cur){
            stk.push(cur);
            cur = cur->left;
        }
        else{
            TreeNode * tmp = stk.top();
            res.push_back(tmp->val);
            stk.pop();
            cur = tmp->right;
        }
    }
    return res;
}


