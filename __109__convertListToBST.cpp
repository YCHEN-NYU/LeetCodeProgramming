/*
 109. Convert Sorted List to Binary Search Tree
 Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST. For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 
 Example:
 Given the sorted linked list: [-10,-3,0,5,9], One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
     0
    / \
  -3   9
  /   /
-10  5
 */

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int val): val(val), next(NULL) {}
};

struct TreeNode{
    int val;
    TreeNode * left, * right;
    TreeNode(int val): val(val), left(NULL), right(NULL) {}
};

ListNode * buildLinkedList(vector<int> & nums){
    if(nums.size() == 0)    return NULL;
    ListNode * head, * tail;
    head = new ListNode(nums[0]);
    tail = head;
    for(int i = 1; i < nums.size(); i++){
        ListNode * newNode = new ListNode(nums[i]);
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

void printLinkedList(ListNode * head){
    if(!head)   return;
    else{
        ListNode * cur = head;
        while(cur){
            cout << cur->val ;
            if(cur->next)   cout << "->";
            cur = cur->next;
        }   cout << endl;
    }
}







