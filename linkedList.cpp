#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int val): val(val), next(NULL) {}
};

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

int main(){
    vector<vector<int>> nums = {{}, {1}, {1, 2}, {1, 2, 3}, {1, 2, 3, 4}, {1, 2, 3, 4, 5}};
//    ListNode * head = buildLinkedList(nums);
//    printLinkedList(head);
    
    for (int i = 0; i < nums.size(); i++) {
        
        ListNode * head = buildLinkedList(nums[i]);
        cout << "head: ";
        printLinkedList(head);
        cout << endl;
        cout << "mid: ";
        ListNode * mid = findMidNode(head);
        printLinkedList(mid);
        cout << endl;
    }
    
    
    return 0;
    
}
