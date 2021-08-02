/*
    Problem Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
*/

// iterative traversal using 2 stacks
// similar to 2 pointer approach

bool findTarget(TreeNode *root, int target) {
    stack<TreeNode*> leftStack, rightStack;
    TreeNode *ptr = root; // maintain a copy of the root node
    // fill the leftStack
    while(ptr) {
        leftStack.push(ptr);
        ptr = ptr->left;
    }
    // fill the rightStack
    ptr = root;
    while(ptr) {
        rightStack.push(ptr);
        ptr = ptr->right;
    }
    // apply 2 pointer approach
    // edge case: root node is a part of 
    while(!leftStack.empty() && !rightStack.empty() && leftStack.top() != rightStack.top()) {
        // fetch the values from stack {cur_min, cur_max}
        TreeNode *left_node = leftStack.top();
        TreeNode *right_node = rightStack.top();

        // if the required pair is found
        if(left_node->val + right_node->val == k)
            return true;
        else if(left_node->val + right_node->val < k) {
            // increase the left pointer
            TreeNode *temp = leftStack.top();
            leftStack.pop();
            // move to the right and add the leftmost nodes in the stack
            temp = temp->right;
            while(temp) {
                leftStack.push(temp);
                temp = temp->left;
            }
        }
        else {
            // decrease the right pointer
            TreeNode *temp = rightStack.top();
            rightStack.pop();
            // move to the left and add the rightmost nodes in the stack
            temp = temp->left;
            while(temp) {
                rightStack.push(temp);
                temp = temp->right;
            }
        }
    }
    return false; // the pair is not found
}