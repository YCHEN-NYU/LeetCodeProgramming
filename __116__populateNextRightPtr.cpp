/*
 116. Populating Next Right Pointers in Each Node
 You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:
 
 struct Node {
 int val;
 Node *left;
 Node *right;
 Node *next;
 }
 Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 
 Initially, all next pointers are set to NULL.
 */

Node* connect(Node* root) {
    Node * p = root;
    helper(p);
    return root;
}

void helper(Node * root){
    if(!root)   return;
    
    while(root->left){
        Node * p = root;
        while(p){
            p->left->next = p->right;
            if(p->next) p->right->next = p->next->left;
            p = p->next;
        }
        root = root->left;
    }
    }
