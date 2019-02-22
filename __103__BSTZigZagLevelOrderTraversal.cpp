/*
 103. Binary Tree Zigzag Level Order Traversal
 Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
 
 For example:
 Given binary tree [3,9,20,null,null,15,7],
     3
    / \
   9   20
  /     \
 15      7
 return its zigzag level order traversal as:
 [
 [3],
 [20,9],
 [15,7]
 ]
 */


vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(!root) return res;
    
    deque<TreeNode *> dQ;
    dQ.push_front(root);
    
    int level = 0;
    
    while(!dQ.empty()){
        int len = dQ.size();
        vector<int> row;
        
        for(int i = 0; i < len; i++){
            // left -> right
            if(level%2 == 0){
                TreeNode * tmp = dQ.back();
                row.push_back(tmp->val);
                dQ.pop_back();
                
                if(tmp->left) dQ.push_front(tmp->left);
                if(tmp->right) dQ.push_front(tmp->right);
            }
            else{
                TreeNode * tmp = dQ.front();
                row.push_back(tmp->val);
                dQ.pop_front();
                
                if(tmp->right) dQ.push_back(tmp->right);
                if(tmp->left) dQ.push_back(tmp->left);
            }
        }
        
        res.push_back(row);
        level++;
        
    }
    
    return res;
    }
