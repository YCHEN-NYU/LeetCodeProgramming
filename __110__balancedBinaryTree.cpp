/*
 110. Balanced Binary Tree
 Given a binary tree, determine if it is height-balanced.
 For this problem, a height-balanced binary tree is defined as:
 a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 
 Example 1:
 Given the following tree [3,9,20,null,null,15,7]:
 
    3
   / \
  9  20
    /  \
   15   7
 Return true.
 
 Example 2:
 
 Given the following tree [1,2,2,3,3,null,null,4,4]:
 
       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
 Return false.
 */

bool isBalanced(TreeNode* root) {
    if(!root)   return true;
    else{
        return (abs(depth(root->left) - depth(root->right)) <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }
}

int depth(TreeNode * root){
    if(!root)   return 0;
    else{
        if(!root->left && !root->right) return 1;
        if(root->left && !root->right)  return 1 + depth(root->left);
        if(!root->left && root->right)  return 1 + depth(root->right);
        return 1 + max(depth(root->left), depth(root->right));
    }
}
