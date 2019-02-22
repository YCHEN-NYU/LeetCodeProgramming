/*
 104. Maximum Depth of Binary Tree
 Given a binary tree, find its maximum depth.
 
 The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 
 Note: A leaf is a node with no children.
 
 Example:
 Given binary tree [3,9,20,null,null,15,7],
     3
    / \
   9  20
      / \
    15   7
 
 */

int maxDepth(TreeNode* root) {
    if(!root)   return 0;
    else{
        if(!root->left && !root->right) return 1;
        else{
            if(root->left && !root->right)
                return 1 + maxDepth(root->left);
            if(!root->left && root->right)
                return 1 + maxDepth(root->right);
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
        }
    }
}
