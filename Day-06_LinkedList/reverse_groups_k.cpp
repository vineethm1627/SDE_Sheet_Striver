/*
    Problem Link: https://leetcode.com/problems/reverse-nodes-in-k-group/
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
class Solution {
    // temp head and tail
    ListNode *th = NULL, *tt = NULL;
public:
    // helper function to calculate the size of the linked list
    int length(ListNode *head) {
        int size = 0;
        while(head) {
            size++;
            head = head->next;
        }
        return size;
    }
    
    // helper function to add node at the starting of the list
    void addFirst(ListNode *node) {
        if(th == NULL)
            th = tt = node;
        else {
            node->next = th;
            th = node;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        // edge cases
        if(!head || !head->next || k == 1)
            return head;
        // find the length of the list
        int size = length(head);
        ListNode *curr = head;
        
        // original head and tails for the final merged linked list
        ListNode *oh = NULL, *ot = NULL;
        
        while(size >= k) {
            int temp = k;
            // reverse the links of K nodes
            while(temp--) {
                // take the left most node
                ListNode *N = curr->next;
                // break the link
                curr->next = NULL;
                addFirst(curr);
                // update values for next iteration
                curr = N;
            }
            // first set of k reversed nodes
            if(!oh) {
                oh = th;
                ot = tt;
            }
            else {
                ot->next = th;
                ot = tt;
            }
            
            // reset th and tt
            th = tt = NULL;
            // decrease size
            size -= k;
        }
        // attach the remaining part: residual group of size < k 
        if(size)
            ot->next = curr;
        return oh;
    }
};