/*
 83. Remove Duplicates from Sorted List
 Given a sorted linked list, delete all duplicates such that each element appear only once.
 
 Example 1:
 Input: 1->1->2
 Output: 1->2
 Example 2:
 
 Input: 1->1->2->3->3
 Output: 1->2->3
 */
#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode * removeDuplicates(ListNode *head){
    ListNode * p = head;
    while(p){
        if(p->next && p->val == (p->next)->val){
            ListNode *tmp = p->next;
            p->next = (p->next)->next;
            delete tmp;
        }
        else{
            p = p->next;
        }
        
    }
    return head;
}

void printLinkedList(ListNode *head){
    ListNode * p = head;
    cout << "*->";
    while(p){
        cout << p->val;
        if(p->next) cout << "->";
        p = p->next;
    }   cout << "->*" << endl;
}

ListNode * initLinkedList(vector<int> &nums){
    if(nums.size() == 0)    return NULL;
    
    ListNode * head = new ListNode(0);
    ListNode * p = head;
    for (int i = 0; i < nums.size(); i++) {
        if(i == 0)  {
            head->val = nums[i];
        }
        else{
            p->next =  new ListNode(nums[i]);
            p = p->next;
        }
    }
    return head;
}

int main(){
    vector<int> nums = {1, 1, 1, 1, 1};
    ListNode * head = initLinkedList(nums);
    printLinkedList(head);
    head = removeDuplicates(head);
    printLinkedList(head);
}
