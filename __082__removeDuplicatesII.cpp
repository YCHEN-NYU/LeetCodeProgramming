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
using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(int val): val(val), next(NULL) {}
};

ListNode * initLinkedList(vector<int> &nums){
    if(nums.size() == 0)    return NULL;
    ListNode * head = Listnode(nums[0]);
    ListNode * p = head;
    for (int i = 1; i < nums.size(); i++) {
        p->next = new ListNode(nums[i]);
        p = p->next;
    }
    return head;
}

void printLinkedList(ListNode * head){
    
}

int main(){
    
}


