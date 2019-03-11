/*
 572. Subtree of Another Tree
 Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.
 Example 1:
 Given tree s:
     3
    / \
   4   5
  / \
 1   2
 Given tree t:
   4
  / \
 1   2
 Return true, because t has the same structure and node values with a subtree of s.
 
 Example 2:
 Given tree s:
      3
     / \
    4   5
   / \
  1   2
 /
0
 Given tree t:
   4
  / \
 1   2
 Return false.

 */
bool isSameTree(TreeNode * t1, TreeNode* t2){
    if(!t1 && !t2) return true;
    
    if((t1 && !t2) || (!t1 && t2))  return false;
    
    if(t1->val != t2->val)
        return false;
    else
        return isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
}


bool isSubtree(TreeNode* s, TreeNode* t) {
    // traverse every node of s from the root
    // return the node as (node->val == t->val)
    // return isSameTree(node, t)
    if(isSameTree(s, t))
        return true;
    else {
        if(s->left && !s->right) return isSubtree(s->left, t);
        if(!s->left && s->right) return isSubtree(s->right, t);
        if(s->left && s->right) return isSubtree(s->left, t) || isSubtree(s->right, t);
        if(!s->left && !s->right) return false;
    }
}


