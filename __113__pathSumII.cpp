

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
    vector<int> tmp;
    helper(root, sum, tmp, res);
    return res;
}

void helper(TreeNode * root, int sum, vector<int> &tmp, vector<vector<int>> &res)  {
    if(!root) return;
    else{
        tmp.push_back(root->val);
        if(!root->left && !root->right && sum == root->val){
            res.push_back(tmp);
            tmp.pop_back();
            return ;
        }
        if(root->left)  helper(root->left, sum - root->val, tmp, res);
        if(root->right) helper(root->right, sum - root->val, tmp, res);
        tmp.pop_back();
    }
}
