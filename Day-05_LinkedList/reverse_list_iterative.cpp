/*
    Problem Link: https://leetcode.com/problems/reverse-linked-list/
*/

struct ListNode {
    int val;
    ListNode *next;

    ListNode(): val(0), next(NULL) {}
    ListNode(int x): val(x), next(NULL) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

ListNode *reverseList(ListNode *head) {
    ListNode *P = NULL;
    ListNode *C = head;
    ListNode *N;

    while(C) {
        N = C->next;
        C->next = P;
        // update pointers
        P = C;
        C = N;
    }
    return P;
}