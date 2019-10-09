/*
 86. Partition List
 Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 
 You should preserve the original relative order of the nodes in each of the two partitions.
 
 Example:
 
 Input: head = 1->4->3->2->5->2, x = 3
 Output: 1->2->2->4->3->5
 */

ListNode* partition(ListNode* head, int x) {
    if(!head || !head->next) return head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *cur = dummy, *tail;
    int len = 1;
    // get the length of the linked list
    ListNode *p = head;
    while(p->next){
        p = p->next;
        len++;
    }
    tail = p;
    // cout << "tail->val = " << tail->val << endl;
    // head: cur->next, tail->next = NULL;
    // len is odd case
    while(len > 0){
        // compare cur->next->val with x, if(cur->next->val)
        if(cur->next->val < x){
            // move cur to the next node
            cur = cur->next;
        }
        else{
            if(cur->next->next){
                // attach cur->next node to tail->next
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                tail->next = tmp;
                tmp->next = NULL;
                tail = tail->next;
            }
            else break;
        }
        len--;
    }
    
    return dummy->next;
}

ListNode* partition(ListNode* head, int x) {
//if(head == NULL || head->next == NULL) return head;

ListNode * lhsHead = NULL, * rhsHead = NULL;
ListNode * lhsTail = NULL, * rhsTail = NULL;

// ListNode * currentNode = head;
//     while(currentNode != NULL){
//         if(currentNode->val < x){
//             // attach to the end of lhsHead
//             if(lhsHead == NULL){
//                 lhsHead = new ListNode(currentNode->val);
//                 lhsTail = lhsHead;
//             }
//             else{
//                 lhsTail->next = new ListNode(currentNode->val);
//                 lhsTail = lhsTail->next;
//             }
//         }
//         else{
//             // attach to the end of rhsHead
//             if(rhsHead == NULL){
//                 rhsHead = new ListNode(currentNode->val);
//                 rhsTail = rhsHead;
//             }
//             else{
//                 rhsTail->next = new ListNode(currentNode->val);
//                 rhsTail = rhsTail->next;
//             }
//         }
//         currentNode = currentNode->next;
//     }


// if(lhsTail != NULL) {
//     lhsTail->next = rhsHead;
//     return lhsHead;
// }
// else{
//     if(rhsHead != NULL)
//         return rhsHead;
//     else
//         return NULL;
// }

// }
