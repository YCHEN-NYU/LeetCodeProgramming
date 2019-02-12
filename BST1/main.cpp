/*
 * Binary Search Tree
 */

#include <iostream>
using namespace std;
// [8, 10, 12, 15, 17, 20, 25]

struct BSTNode {
    int data;
    BSTNode * left;
    BSTNode * right;
};

BSTNode * GetNewNode(int data){
    BSTNode * newNode = new BSTNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

BSTNode * Insert(BSTNode * root, int data){
    if(root == NULL){
        root = GetNewNode(data);
        return root;
    }
    else if(data <= root->data){
        root->left = Insert(root->left, data);
    }
    else {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool Search(BSTNode * root, int data){
    if(root == NULL){
        return false;
    }
    else if(root->data == data) return true;
    else if(data <= (root->data)) return Search(root->left, data);
    else return Search(root->right, data);
}


int main() {
    // Initialize the root pointer as empty
    BSTNode * root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    int target=0;
    do {
        cout << "target = ";
        cin >> target;
        cout << "\n target found: " << boolalpha << Search(root, target) << endl;
    } while(target != -1);
    return 0;
}