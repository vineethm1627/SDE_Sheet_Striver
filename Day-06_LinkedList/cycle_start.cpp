/*
    Problem Link: https://leetcode.com/problems/linked-list-cycle-ii/
*/

// return the node where the cycle begins
ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while(fast && fast->next) {
        slow = slow->next; // 1 step
        fast = fast->next->next; // 2 steps

        // cycle detected
        if(slow == fast) {
            // move fast to the head
            fast = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
