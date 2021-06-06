/*
    Problem Link: https://leetcode.com/problems/palindrome-linked-list/
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

ListNode *reverse(Listnode *reverse) {
    ListNode *P = NULL;
    ListNode *C = head;
    ListNode *N;

    while(C) {
        N = C->next;
        C->next = P;
        P = C;
        C = N;
    }
    return P;
}

bool isPalindrome(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    // find middle of the linked list
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // move fast to head
    fast = head;
    slow = reverse(slow);

    while(slow) {
        if(slow->val != fast->val)
            return false;
        // move 1 step each
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}
