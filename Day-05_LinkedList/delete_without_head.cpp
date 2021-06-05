/*
    Problem Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void deleteNode(ListNode *node) {
    // copy the value
    node->val = node->next->val;
    // delete the next node
    node->next = node->next->next;
}