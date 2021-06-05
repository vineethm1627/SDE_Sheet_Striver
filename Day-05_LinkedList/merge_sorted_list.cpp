/*
    Problem Link: https://leetcode.com/problems/merge-two-sorted-lists/
*/

struct ListNode {
    int val;
    ListNode *next;

    ListNode(): val(0), next(NULL) {}
    ListNode(int x): val(x), next(NULL) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
    // base cases
    if(!l1)
        return l2;
    else if(!l2)
        return l1;
    
    if(l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}