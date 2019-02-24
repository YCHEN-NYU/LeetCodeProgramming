/*
129. Sum Root to Leaf Numbers
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

Note: A leaf is a node with no children.

Example:

Input: [1,2,3]
  1
 / \
2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
Example 2:

Input: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
*/

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// recursive method
int sumNumbers(TreeNode * root){
    return helper(root, 0);
}

void helper(TreeNode * root, int sum){
    if(!root)   return 0;
    else{
        if(!root->left && !root->right) return sum*10 + root->val;
        else
            return helper(root->left, sum*10 + root->val) + helper(root->right, sum*10 + root->val);
    }
}


// iterative method using postorder traversal
int sumNumbers(TreeNode* root) {
    
    stack<TreeNode*> nodes;
    if (!root)
        return 0;
    
    int total = 0;
    int current = 0;
    TreeNode* last = nullptr;
    while (root || !nodes.empty())
    {
        if (root)
        {
            nodes.push(root);
            current *= 10;
            current += root->val;
            root = root->left;
        }
        else
        {
            root = nodes.top();
            if (root->right && root->right != last)
            {
                root = root->right;
            }
            else
            {
                nodes.pop();
                last = root;
                // only add sum of leaf node
                if (root->right == nullptr && root->left == nullptr)
                    total += current;
                current /= 10;
                root = nullptr;
            }
        }
    }
    
    return total;
}
