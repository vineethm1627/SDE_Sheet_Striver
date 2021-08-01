/*
    Problem Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
*/

// iterative inorder traversal using stack
int kthSmallest(TreeNode *root, int k) {
   stack<TreeNode*> s;
   while(!s.empty() || root) {
        // reach the left most node
        while(root) {
           s.push(root);
           root = root->left;
        }
        // pop the left most node
        root = s.top();
        s.pop();
        i(--k == 0)
            return root->val;
        // move to the right subtree
        root = root->right;
   }
   return -1;
}