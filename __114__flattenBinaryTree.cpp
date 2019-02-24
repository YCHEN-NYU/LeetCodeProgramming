

void flatten(TreeNode* root) {
    TreeNode * prev = NULL;
    helper(root, prev);
}

void helper(TreeNode * root, TreeNode * &prev){
    if(!root)   return;
    else{
        helper(root->right, prev);
        helper(root->left, prev);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
}



void flatten(TreeNode *root) {
    while (root) {
        if (root->left && root->right) {
            TreeNode* t = root->left;
            while (t->right)
                t = t->right;
            t->right = root->right;
        }
        
        if(root->left)
            root->right = root->left;
        root->left = NULL;
        root = root->right;
    }
}



void flatten(TreeNode *root) {
    TreeNode*now = root;
    while (now)
    {
        if(now->left)
        {
            //Find current node's prenode that links to current node's right subtree
            TreeNode* pre = now->left;
            while(pre->right)
            {
                pre = pre->right;
            }
            pre->right = now->right;
            //Use current node's left subtree to replace its right subtree(original right
            //subtree is already linked by current node's prenode
            now->right = now->left;
            now->left = NULL;
        }
        now = now->right;
    }
    }
