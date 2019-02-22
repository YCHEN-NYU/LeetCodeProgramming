/*
 102. Binary Tree Level Order Traversal
 Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 
 For example:
 Given binary tree [3,9,20,null,null,15,7],
 3
 / \
 9  20
 /  \
 15   7
 
 return its level order traversal as:
 [
 [3],
 [9,20],
 [15,7]
 ]
 */


vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(!root)   return res;
    
    queue<TreeNode *> Q;
    Q.push(root);
    
    while(!Q.empty()){
        int len = Q.size();
        vector<int> tmp;
        for(int i = 0; i < len; i++){
            TreeNode * p = Q.front();
            Q.pop();
            tmp.push_back(p->val);
            if(p->left) Q.push(p->left);
            if(p->right) Q.push(p->right);
        }
        res.push_back(tmp);
    }
    return res;
    }
