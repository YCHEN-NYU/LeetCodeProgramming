/*
 203. Remove Linked List Elements
 Remove all elements from a linked list of integers that have value val.
 
 Example:
 Input:  1->2->6->3->4->5->6, val = 6
 Output: 1->2->3->4->5
 */
ListNode* removeElements(ListNode* head, int val) {
    ListNode * dummy = new ListNode(0);
    dummy->next = head;
    ListNode * cur = dummy;
    
    while(cur){
        if(cur->next && cur->next->val == val)
            cur->next = cur->next->next;
        else
            cur = cur->next;
    }
    return dummy->next;
}
