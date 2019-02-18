/*
 25. Reverse Nodes in k-Group
 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 
 Example:
 Given this linked list: 1->2->3->4->5
 For k = 2, you should return: 2->1->4->3->5
 For k = 3, you should return: 3->2->1->4->5
 
 Note:
 Only constant extra memory is allowed.
 You may not alter the values in the list's nodes, only nodes itself may be changed.
 
 https://leetcode.com/problems/reverse-nodes-in-k-group/discuss/11457/20-line-iterative-C%2B%2B-solution
 */
ListNode *reverseKGroup(ListNode *head, int k) {
    if(head==NULL||k==1) return head;
    int num=0;
    ListNode *preheader = new ListNode(-1);
    preheader->next = head;
    ListNode *cur = preheader, *nex, *tmp, *pre = preheader;
    while(cur = cur->next)
        num++;
    while(num>=k) {
        cur = pre->next;
        nex = cur->next;
        for(int i=1;i<k;i++) {
            tmp= nex->next;
            nex->next = pre->next;
            pre->next = nex;
            cur->next = tmp;
            nex = tmp;
        }
        pre = cur;
        num-=k;
    }
    return preheader->next;
}
