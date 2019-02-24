/*
111. Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
Note: A leaf is a node with no children.

Example:
Given binary tree [3,9,20,null,null,15,7],

  3
 / \
9  20
  /  \
15    7
 return its minimum depth = 2.
*/

int minDepth(TreeNode* root) {
    if(!root)   return 0;
    else{
        if(!root->left && !root->right) return 1;
        if(root->left && !root->right)  return 1 + minDepth(root->left);
        if(!root->left && root->right)  return 1 + minDepth(root->right);
        return 1 + min(minDepth(root->left), minDepth(root->right));
        
    }
}
