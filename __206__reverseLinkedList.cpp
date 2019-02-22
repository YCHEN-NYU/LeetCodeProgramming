/*206. Reverse Linked List
Reverse a singly linked list.

Example:
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

Follow up:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/
#include <iostream>
#include <vector>
#include "list.h"
using namespace std;

ListNode* reverseList(ListNode* head) {
    if(!head || !head->next)    return head;
    
    ListNode * cur = head;
    int i = 0;
    while(cur->next){
        ListNode * p = cur->next;
        cur->next = p->next;
        p->next = head;
        head = p;
    }
    return head;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode * head = buildLinkedList(nums);
    printLinkedList(head);
    ListNode * revHead = reverseList(head);
    printLinkedList(revHead);
    return 0;
}
