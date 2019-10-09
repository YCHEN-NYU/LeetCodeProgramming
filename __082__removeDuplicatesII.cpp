/*
82. Remove Duplicates from Sorted List II
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

 Example 1:
Input: 1->2->3->3->4->4->5
Output: 1->2->5

 Example 2:
Input: 1->1->1->2->3
Output: 2->3
 */
#include <iostream>
#include <vector>
#include "list.h"


void removeDuplicatesI(ListNode * head){
    if(!head || !head->next)    return;
    
    ListNode * cur = head;
    while(cur){
        if(cur->next && cur->val == cur->next->val){
            // skip cur->next
            ListNode * tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        }
        else    cur = cur->next;
    }
}

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* cur = dummy;
    int duplicate;
    while (cur->next && cur->next->next) {
        if (cur->next->val == cur->next->next->val) {
            duplicate = cur->next->val;
            while (cur->next && cur->next->val == duplicate) {
                cur->next = cur->next->next; // skip cur->next node
            }
        }
        else {
            cur = cur->next;
        }
    }
    return dummy->next;
}

// use a set to store duplicates from the linked list, could be use for unsorted linked list
// ListNode* deleteDuplicates(ListNode* head) {
//     if(!head || !head->next) return head;
//     // starting from the head node, if 
//     ListNode * cur = head;
//     // if cur->next && cur->val = cur->next
//     // use a set to store duplicates
//     unordered_set<int> numSet;
//     while(cur->next){
//         if(cur->val == cur->next->val){
//             numSet.insert(cur->val);
//             // skip the next node, leave cur untouch
//             ListNode * tmp = cur->next;
//             cur->next = cur->next->next;
//             delete tmp;
//         }
//         else{
//             // move cur to the next
//             cur = cur->next;
//         }
//     }
    
//     ListNode * dummy = new ListNode(0);
//     dummy->next = head;
//     ListNode *p = dummy;
//     while(p->next){
//         if(numSet.find(p->next->val) != numSet.end()){
//             p->next = p->next->next;
//         }
//         else{
//             p = p->next;
//         }
//     }
//     return dummy->next;
// }

int main(){
    vector<int> nums = {1, 2, 2, 2, 3, 4, 4};
    ListNode * head = buildLinkedList(nums);
    printLinkedList(head);
    ListNode * newHead = deleteDuplicates(head);
    printLinkedList(newHead);
    return 0;
}


