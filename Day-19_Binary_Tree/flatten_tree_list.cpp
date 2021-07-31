/*
    Problem Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
*/

// Morris like traversal
void flatten(TreeNode *root) {
    // edge case
    if(!root)
        return;
    
    while(root) {
        // connect left subtree to the right
        if(root->left) {
            TreeNode *leftRightMost = root->left;
            while(leftRightMost->right)
                leftRightMost = leftRightMost->right;
            // rewire the connections
            leftRightMost->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        // move to the next node
        root = root->right;
    }
}