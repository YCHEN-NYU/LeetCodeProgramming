#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(int val): val(val), next(NULL) {}
};

ListNode * buildLinkedList(vector<int> & nums){
    if(nums.size() == 0)    return NULL;
    else{
        ListNode * head = new ListNode(nums[0]);
        ListNode * cur = head;
        for (int i = 1; i < nums.size(); i++) {
            ListNode * newNode = new ListNode(nums[i]);
            cur->next = newNode;
            cur = newNode;
        }
        return head;
    }
}

ListNode * addTwoNumbers(ListNode * l1, ListNode * l2){
    int carry = 0, sum = 0;
    ListNode * preHead = new ListNode(0);
    ListNode * cur = preHead;
    while (l1 || l2 || carry) {
        sum = (l1? l1->val : 0) + (l2? l2->val : 0) + carry;
        carry = sum/10;
        
        ListNode * newNode = new ListNode(sum%10);
        cur->next = newNode;
        cur = newNode;
        
        if(l1)  l1 = l1->next;
        if(l2)  l2 = l2->next;
    }
    return preHead->next;
}

void printLinkedList(ListNode * head){
    if(!head) return;
    else{
        ListNode * cur = head;
        while(cur){
            cout << cur->val;
            if(cur->next)   cout << "->";
            cur = cur->next;
        }   cout << endl;
    }
}



int main(){
    vector<vector<int>> numList = {{2, 4, 3}, {5, 6, 4}};
    ListNode * l1, * l2;
    
    l1 = buildLinkedList(numList[0]);
    cout << "l1: ";
    printLinkedList(l1);
    
    l2 = buildLinkedList(numList[1]);
    cout << "l2: ";
    printLinkedList(l2);
    ListNode * l = addTwoNumbers(l1, l2);
    cout << "l1 + l2 = ";
    printLinkedList(l);
    return 0;
}
