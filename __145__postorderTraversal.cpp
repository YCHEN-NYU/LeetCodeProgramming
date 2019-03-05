/*
 145. Binary Tree Postorder Traversal
Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
1
 \
  2
 /
3

Output: [3,2,1]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/



 vector<int> postorderTraversal(TreeNode* root) {
   vector<int> res;
   stack<TreeNode*> stk;
   if(root) stk.push(root);
   while(!stk.empty()){
     TreeNode* node = stk.top();
     stk.pop();
     if(node->left) stk.push(node->left);
     if(node->right) stk.push(node->right);
     res.push_back(node->val);
   }
   reverse(res.begin(), res.end());
   return res;
 }


/*
 vector<int> res;
 vector<int> postorderTraversal(TreeNode *root){
 if(root){
 if(!root->left){
 if(!root->right)  res.push_back(root->val);
 else {
 postorderTraversal(root->right);
 res.push_back(root->val);
 }
 }
 else {
 if(!root->right) {
 postorderTraversal(root->left);
 res.push_back(root->val);
 }
 else {
 postorderTraversal(root->left);
 postorderTraversal(root->right);
 res.push_back(root->val);
 }
 }
 }
 return res;
 
 }
 */
