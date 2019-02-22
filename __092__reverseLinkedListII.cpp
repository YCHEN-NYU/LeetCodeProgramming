/*
 92. Reverse Linked List II
 Reverse a linked list from position m to n. Do it in one-pass.
 Note: 1 ≤ m ≤ n ≤ length of list.
 
 Example:
 Input: 1->2->3->4->5->NULL, m = 2, n = 4
 Output: 1->4->3->2->5->NULL
 */
#include <iostream>
#include <vector>
#include "list.h"
using namespace std;

ListNode* reverseBetween(ListNode* head, int m, int n) {
    // a dummy preHead
    ListNode * preHead = new ListNode(0);
    preHead->next = head;
    ListNode * p = preHead; // [dummy]->[1]->[2]->[3]->[4]->[5]->NULL
    for(int i = 0; i < m - 1; i++) p = p->next; // m - 1 =  2 - 1 = 1, i = 0, move one step forward
    
    // p = [1]->[2]->[3]->[4]->[5]->NULL, the node before the one to be reversed
    ListNode * segmentHead = p->next; // [2]->[3]->[4]->[5]->NULL
    ListNode * node = segmentHead->next;  // the node to be reversed, [3]->[4]->[5]->NULL
    // m = 2, n = 4, so j = 0, 1
    for(int j = 0; j < n - m; j++){
        segmentHead->next = node->next; // segmentHead = [2]->[4]->[5]->NULL
        node->next = p->next; // [3]->[2]->[3]->[4]->[5]->NULL
        p->next = node; // [1]->[3]->[2]->[4]->[5]->NULL
        node = segmentHead->next; // [4]->[5]->NULL
    }
    
    return preHead->next;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode * head = buildLinkedList(nums);
    printLinkedList(head);
    ListNode * newHead = reverseBetween(head, 2, 4);
    printLinkedList(newHead);
}
