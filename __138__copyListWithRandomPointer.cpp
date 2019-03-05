/*
 138. Copy List with Random Pointer
 A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 Return a deep copy of the list.
 
 Example 1:
 Input:
 {"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
 
 Explanation:
 Node 1's value is 1, both of its next and random pointer points to Node 2.
 Node 2's value is 2, its next pointer points to null and its random pointer points to itself.
 
 Note:
 You must return the copy of the given head as a reference to the cloned list.

 */




/*
 // Definition for a Node.
 class Node {
 public:
 int val;
 Node* next;
 Node* random;
 
 Node() {}
 
 Node(int _val, Node* _next, Node* _random) {
 val = _val;
 next = _next;
 random = _random;
 }
 };
 */
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)   return head;
        
        // iterate through the original list, copy nodes
        Node * l1 = head, * l2;
        while(l1){
            l2 = new Node(l1->val); // create a new node with l1->val
            l2->next = l1->next; // l2 linked to the next node of l1
            l1->next = l2; // l1 linked to l2
            l1 = l1->next->next; // move forward two nodes
        }
        
        // copy the random pointers
        Node * newHead = head->next;
        l1 = head;
        while(l1){
            if(l1->random) l1->next->random = l1->random->next;
            l1 = l1->next->next;
        }
        
        // restore the original linked list
        l1 = head;
        while(l1){
            l2 = l1->next;
            l1->next = l2->next;
            if(l2->next)    l2->next = l2->next->next;
            l1 = l1->next;
        }
        
        return newHead;
    }
};


