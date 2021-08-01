/*
    Problem Link: https://leetcode.com/problems/validate-binary-search-tree/
*/

// helper function to validate BST using range validation
bool isBST(TreeNode *root, long long min_val = -1e10, long long max_val = 1e10) {
    // base case
    if(!root)
        return true;
    // check if the node data lies in the range
    if(root->val > min_val && root->val < max_val) {
        // recursive calls
        if(isBST(root->left, min_val, root->val) && isBST(root->right, root->val, max_val) 
            return true;
    }
    return false;
}

bool isValidBST(TreeNode *root) {
    return isBST(root);
}