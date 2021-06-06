/*
    Problem Link: https://leetcode.com/problems/intersection-of-two-linked-lists/
*/

ListNode *getIntersectionNode(ListNode *headA, Listnode *headB) {
    ListNode *a = headA;
    ListNode *b = headB;

    while(a != b) {
        a = (a == NULL) ? headB : a->next;
        b = (b == NULL) ? headA : b->next;
    }
    return a;
}
