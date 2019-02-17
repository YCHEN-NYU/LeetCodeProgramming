/*
 21. Merge Two Sorted Lists
 Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 
 Example:
 Input: 1->2->4, 1->3->4
 Output: 1->1->2->3->4->4
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

ListNode * mergeTwoLists(ListNode * l1, ListNode * l2){
    if(!l1 && !l2)  return NULL;
    if(l1 && !l2)   return l1;
    if(!l1 && l2)   return l2;
    ListNode * head, * cur;
    head = new ListNode(0);
    cur = head;
    while(l1 && l2){
        if(l1->val < l2->val){
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
        }
        else{
            cur->next = l2;
            cur = cur->next;
            l2 = l2->next;
        }
    }
    if(l1)  cur->next = l1;
    else{
        if(l2) cur->next = l2;
        else cur->next = NULL;
    }
    return head->next;
}

int main(){
    vector<vector<int>> numList = {{-1, 1, 2, 5, 10}, {0, 1, 3, 4, 7}};
    ListNode * l1 = buildLinkedList(numList[0]);
    cout << "l1: "; printLinkedList(l1);
    ListNode * l2 = buildLinkedList(numList[1]);
    cout << "l2: "; printLinkedList(l2);
    ListNode * l = mergeTwoLists(l1, l2);
    cout << "l: "; printLinkedList(l);
    return 0;
}


