/*
    Problem Link: https://leetcode.com/problems/rotate-list/description/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

ListNode *rotateRight(ListNode *head, int k) {
    // edge cases
    if(!head || !head->next || k == 0)
        return head;

    ListNode *curr = head;
    int len = 1;
    while(curr->next) {
        len++;
        curr = curr->next;
    }
    // curr is on the last node: connect it with the head to form a loop
    curr->next = head;
    k %= len;
    k = len - k;

    while(k--) 
        curr = curr->next;
    
    // update the head node
    head = curr->next;
    // break the link
    curr->next = NULL;

    return head;
}