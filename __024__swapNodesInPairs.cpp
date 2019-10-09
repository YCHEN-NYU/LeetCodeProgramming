/*
 24. Swap Nodes in Pairs
 Given a linked list, swap every two adjacent nodes and return its head.
  You may not modify the values in the list's nodes, only nodes itself may be changed.
 Example:
  Given 1->2->3->4, you should return the list as 2->1->4->3.
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

// recursive method
ListNode * swapPairs(ListNode * head){
    if(!head || !head->next)    return head;
    else{
        ListNode * tmp = head->next;
        head->next = swapPairs(head->next->next);
        tmp->next = head;
        head = tmp;
        return head;
    }
}

int main(){
    vector<vector<int>> numList = {{}, {1}, {1, 2}, {1, 2, 3, 4, 5}};
    
    ListNode * l;
    for(int i = 0; i < numList.size(); i++){
        ListNode * head = buildLinkedList(numList[i]);
        l = swapPairs(head);
        cout << "l: "; printLinkedList(l);
    }
    return 0;
}
