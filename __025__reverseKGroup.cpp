/*
 25. Reverse Nodes in k-Group
 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 
 Example:
 
 Given this linked list: 1->2->3->4->5
 
 For k = 2, you should return: 2->1->4->3->5
 
 For k = 3, you should return: 3->2->1->4->5
 
 Note:
 
 Only constant extra memory is allowed.
 You may not alter the values in the list's nodes, only nodes itself may be changed.
 */
#include <iostream>
#include <vector>
using namespace std;

/*
 -1 -> 1 -> 2 -> 3 -> 4 -> 5
 |    |    |    |
 pre  cur  nex  tmp
 
 -1 -> 2 -> 1 -> 3 -> 4 -> 5
 |         |    |    |
 pre       cur  nex  tmp
 
 -1 -> 3 -> 2 -> 1 -> 4 -> 5
 |              |    |    |
 pre            cur  nex  tmp
 Above is how it works inside one group iteration(for example, k=3)
 */

ListNode * reverseKGroup(ListNode *head, int k){
    if(!head || k == 1) return head;
    int num = 0;
    ListNode *preHead = new ListNode(0);
    preHead->next = head;
    ListNode *cur = preHead, *nex, *pre = preHead;
    while(cur = cur->next) num++;
    
    while(num >= k){
        cur = pre->next;
        nex = cur->next;
        for(int i = 1; i < k; i++){
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        num -= k;
    }

    return preHead->next;
}

//ListNode * reverseKGroup(ListNode *head, int k){
//    if(!head || !head->next || k == 1) return head;
//    
//    ListNode *dummy = new ListNode(0);
//    dummy->next = head;
//    ListNode *prev = dummy, *cur = dummy, *nxt;
//
//    int len = 0; // get the number of nodes in the list
//    while(cur->next){
//        cur = cur->next;
//        len++;
//    }
//}

int main(){
    
}


