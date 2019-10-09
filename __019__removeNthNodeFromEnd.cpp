/*
 19. Remove Nth Node From End of List
 Given a linked list, remove the n-th node from the end of list and return its head.
 
 Example:
 Given linked list: 1->2->3->4->5, and n = 2.
 After removing the second node from the end, the linked list becomes 1->2->3->5.
 Note:
 Given n will always be valid.
 Follow up:
 Could you do this in one pass?
 */

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int val): val(val), next(NULL) {}
};

void printLinkedList(ListNode * head){
    ListNode * cur = head;
    while(cur){
        cout << cur->val;
        if(cur->next)  cout << "->";
        cur = cur->next;
    }   cout << endl;
}

ListNode * buildLinkedList(vector<int> & nums){
    if(nums.size() == 0)    return NULL;
    else{
        ListNode * head = new ListNode(nums[0]);
        ListNode * cur = head;
        for (int i = 1; i < nums.size(); i++) {
            ListNode * newNode = new ListNode(nums[i]);
            cur->next = newNode;
            cur = cur->next;
        }
        return head;
    }
}

int getLength(ListNode * head){
    int len = 0;
    ListNode * cur = head;
    while(cur){
        len++;
        cur = cur->next;
    }
    return len;
}


// ListNode* removeNthFromEnd(ListNode* head, int n) {
//     int len = getLength(head);
//     if(n == len)    return head->next;
    
//     ListNode * cur = head;
//     int i = len - n - 1;
//     while(i > 0){
//         cur = cur->next;
//         i--;
//     }
//     if(cur->next)
//         cur->next = cur->next->next;
//     return head;
// }

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode * dummy = new ListNode(0);
    dummy->next = head;
    ListNode *fast = dummy, *slow = dummy;
    // move fast pointer n times from dummy
    while(n > 0){
        fast = fast->next;
        n--;
    }
    // move slow & fast pointers till fast->next == NULL
    while(fast && fast->next){
        fast = fast->next;
        slow = slow->next;
    }
    
    // remove the node slow->next
    ListNode *tmp = slow->next;
    slow->next = slow->next->next;
    delete tmp; // recycle memory space 
    
    return dummy->next;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode * head = buildLinkedList(nums);
    printLinkedList(head);
    ListNode * p = removeNthFromEnd(head, 5);
    printLinkedList(p);
    
    return 0;
}
