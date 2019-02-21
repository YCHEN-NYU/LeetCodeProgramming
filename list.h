#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <vector>
using namespace std;

//template <class T>
struct ListNode {
    int val;
    ListNode * next;
    ListNode(int val): val(val), next(NULL) {}
};

//template <class T>
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

//template <class T>
ListNode * findMidNode(ListNode * head){
    if(!head)   return NULL;
    else{
        ListNode * fast, * slow;
        fast = head;
        slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
}

//template <class T>
void printLinkedList(ListNode * head){
    if(!head)   return;
    else{
        ListNode * cur = head;
        while(cur){
            cout << cur->val ;
            if(cur->next)   cout << "->";
            cur = cur->next;
        }
        cout << "->NULL" << endl;
    }
}

#endif
