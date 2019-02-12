/*
 21. Merge Two Sorted Lists: Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 
 Example:
 Input: 1->2->4, 1->3->4
 Output: 1->1->2->3->4->4
 */

#include <iostream>
#include <vector>
using namespace std;

// struct for linked list node
struct ListNode {
    int val;
    ListNode * next;
    ListNode(int val): val(val), next(NULL) {}
};

// build a linked list
ListNode * buildList(vector<int> &nums){
    if(nums.size() == 0)    return NULL;
    else{
        ListNode * head = new ListNode(nums[0]);
        ListNode * tail = head;
        for (int i = 1; i < nums.size(); i++) {
            tail->next = new ListNode(nums[i]);
            tail = tail->next;
        }
        return head;
    }
}

// print a linked list
void printList(ListNode * head){
    if(!head)   return;
    else{
        ListNode * cur = head;
        while(cur){
            cout << cur->val;
            if(cur->next)   cout << "->";
            cur = cur->next;
        }   cout << endl;
    }
}

// merge two sorted linked lists
ListNode * mergeTwoLists(ListNode * l1, ListNode * l2){
    if(!l1 && l2)   return l2;
    else{
        if(l1 && !l2) return l1;
        else{
            ListNode * preHead = new ListNode(0);
            ListNode * cur = preHead;
            while(l1 && l2){
                if(l1->val < l2->val){
                    cur->next = l1;
                    l1 = l1->next;
                }
                else{
                    cur->next = l2;
                    l2 = l2->next;
                }
                cur = cur->next;
            }
            cur->next = l1? l1 : l2;
            return preHead->next;
        }
    }
}

int main(){
    vector<int> nums1 = {1, 2, 4}, nums2 = {1, 3, 4};
    ListNode * l, * l1, * l2;
    l1 = buildList(nums1);
    printList(l1);
    l2 = buildList(nums2);
    printList(l2);
    l = mergeTwoLists(l1, l2);
    printList(l);
    return 0;
}


