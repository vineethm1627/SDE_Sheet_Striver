/*
    Problem Link: https://leetcode.com/problems/linked-list-cycle/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while(fast && fast->next) {
        slow = slow->next; // 1 step
        fast = fast->next->next; // 2 steps

        if(slow == fast)
            return true;
    }
    return false;
}