/*
 23. Merge k Sorted Lists
 Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 
 Example:
 Input:
 [
 1->4->5,
 1->3->4,
 2->6
 ]
 Output: 1->1->2->3->4->4->5->6
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



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
template <class T> struct greater{
    /* overload the oeprator() */
    bool operator()(const ListNode *a, const ListNode *b){
        return a->val > b->val;
    }
};

template <class T> struct less{
    bool operator() (const ListNode *a, const ListNode *b){
        return a->val < b->val;
    }
};


ListNode* mergeKLists(vector<ListNode*>& lists) {
    /* put the first element of each list into a priority queue */
    priority_queue<ListNode *, vector<ListNode *>, greater> q;
    
    for(auto list : lists){
        if(list) q.push(list);
    }
    
    ListNode * preHead = new ListNode(0);
    ListNode * curr = preHead;
    while(!q.empty()){
        ListNode * tmp = q.top();
        q.pop();
        
        curr->next = tmp;
        curr = curr->next;
        
        if(tmp->next) q.push(tmp->next);
    }
    
    return preHead->next;
}




/*
bool hasNonEmptyList(vector<ListNode*>& lists){
    for(int i = 0; i < lists.size(); i++)  if(lists[i] != NULL) return true;
    return false;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode * PreHead = new ListNode(0), *p = PreHead;
    
    while(hasNonEmptyList(lists)){
        ListNode * minNode = new ListNode(INT_MAX);
        int minIndex, count = 0;
        for(int i = 0; i < lists.size(); i++){
            if(lists[i] != NULL && count == 0) {
                minNode = lists[i];
                minIndex = i;
                count++;
            }
            else if(lists[i] != NULL && lists[i]->val < minNode->val) {
                minNode = lists[i];
                minIndex = i;
                count++;
            }
        }
        // move on to the next node pointer
        lists[minIndex] = lists[minIndex]->next;
        p->next = minNode;
        p = p->next;
    }
    
    return PreHead->next;
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

ListNode * mergeKLists(vector<ListNode *> &lists){
    if(lists.size() < 2) return lists[0];
    ListNode * l = mergeTwoLists(lists[0], lists[1]);
    
    for (int i = 2; i < lists.size(); i++) {
        l = mergeTwoLists(l, lists[i]);
    }
    return l;
}

*/

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
