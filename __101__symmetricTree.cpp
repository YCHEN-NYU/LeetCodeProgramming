/*
 101. Symmetric Tree
 Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 
     1
    / \
   2   2
  / \ / \
 3  4 4  3
 But the following [1,2,2,null,3,null,3] is not:
     1
    / \
   2   2
    \   \
     3   3
 Note:
 Bonus points if you could solve it both recursively and iteratively.
 */

bool isSymmetric(TreeNode* root) {
    if(!root)   return true;
    else{
        return helper(root->left, root->right);
    }
}

bool helper(TreeNode * leftNode, TreeNode * rightNode){
    if(!leftNode && !rightNode) return true;
    if(!leftNode && rightNode)  return false;
    if(leftNode && !rightNode)  return false;
    if(leftNode->val != rightNode->val) return false;
    return  helper(leftNode->left, rightNode->right) &&
    helper(leftNode->right, rightNode->left);
    
}
