/*
    Problem Link: https://leetcode.com/problems/middle-of-the-linked-list/
*/

struct ListNode {
    int val;
    ListNode *next;

    ListNode(): val(0), next(NULL) {}
    ListNode(int x): val(x), next(NULL) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

ListNode *middleNode(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    // edge case: empty / 1 node
    if(head || head->next)
        return head;
    
    while(fast && fast->next) {
        slow = slow->next; // 1 step
        fast = fast->next->next; // 2 steps
    }
    return slow;
}