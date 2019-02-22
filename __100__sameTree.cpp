/*
 100. Same Tree
 Given two binary trees, write a function to check if they are the same or not.
 
 Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
 */



bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p && !q)    return true;
    if((!p && q) || (p && !q))  return false;
    
    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
