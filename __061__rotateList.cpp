#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(int val): val(val), next(NULL) {}
};

ListNode * buildList(vector<int> & nums){
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

ListNode * rotateList(ListNode * head, int k){
    if(!head || k == 0) return head;
    else{
        ListNode * tail = head;
        int len = 1; // length of the linked list
        while(tail->next){
            tail = tail->next;
            len++;
        }
        
        // linked the tail to the head, forming a circular linked list
        tail->next = head;
        k = k % len;
        for (int i = 0; i < len - k; i++) {
            tail = tail->next;
        }
        head = tail->next;
        tail->next = NULL;
        return head;
    }
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 2;
    ListNode * head = buildList(nums);
    printList(head);
    ListNode * newList = rotateList(head, k);
    printList(newList);
    return 0;
}
