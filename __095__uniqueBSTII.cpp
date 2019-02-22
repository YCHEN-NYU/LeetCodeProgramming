/*
 95. Unique Binary Search Trees II
 Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.
 
 Example:
 
 Input: 3
 Output:
 [
 [1,null,3,2],
 [3,2,null,1],
 [3,1,null,null,2],
 [2,1,3],
 [1,null,2,null,3]
 ]
 Explanation:
 The above output corresponds to the 5 unique BST's shown below:
 
 1        3    3       2      1
 \       /     /      / \      \
 3      2      1     1   3      2
 /     /       \                 \
 2    1         2                 3
 */


TreeNode* clone(TreeNode* root){
    if(root == nullptr)
        return nullptr;
    TreeNode* newroot = new TreeNode(root->val);
    newroot->left = clone(root->left);
    newroot->right = clone(root->right);
    return newroot;
}

vector<TreeNode *> generateTrees(int n) {
    vector<TreeNode *> res(1,nullptr);
    for(int i = 1; i <= n; i++){
        vector<TreeNode *> tmp;
        for(int j = 0; j<res.size();j++){
            TreeNode* oldroot = res[j];
            TreeNode* root = new TreeNode(i);
            TreeNode* target = clone(oldroot);
            root->left = target;
            tmp.push_back(root);
            
            if(oldroot!=nullptr){
                TreeNode* tmpold = oldroot;
                while(tmpold->right!=nullptr){
                    TreeNode* nonroot = new TreeNode(i);
                    TreeNode *tright = tmpold->right;
                    tmpold->right = nonroot;
                    nonroot->left = tright;
                    TreeNode *target = clone(oldroot);
                    tmp.push_back(target);
                    tmpold->right = tright;
                    tmpold = tmpold->right;
                }
                tmpold->right = new TreeNode(i);
                TreeNode *target = clone(oldroot);
                tmp.push_back(target);
                tmpold->right = nullptr;
            }
        }
        res=tmp;
    }
    return res;
}
