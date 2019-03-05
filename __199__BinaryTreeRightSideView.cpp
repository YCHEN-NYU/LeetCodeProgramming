/*
 199. Binary Tree Right Side View
 Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 
 Example:
 
 Input: [1,2,3,null,5,null,4]
 Output: [1, 3, 4]
 Explanation:
 
    1            <---
  /   \
 2     3         <---
  \     \
   5     4       <---
 */

// recursive
vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    int level = 1;
    // root, right, left
    helper(root, level, res);
    return res;
}

void helper(TreeNode * root, int level, vector<int> &res){
    if(!root)   return;
    
    if(res.size() < level){
        res.push_back(root->val);
    }
    
    helper(root->right, level + 1, res);
    helper(root->left, level + 1, res);
}


// iterative
vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if(!root)   return res;
    queue<TreeNode *> Q;
    Q.push(root);
    while(!Q.empty()){
        int len = Q.size();
        for(int i = 0; i < len; i++){
            TreeNode * tmp = Q.front();
            Q.pop();
            if(i == len - 1) res.push_back(tmp->val);
            if(tmp->left) Q.push(tmp->left);
            if(tmp->right) Q.push(tmp->right);
        }
    }
    return res;
}
