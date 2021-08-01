/*
    Problem Link: https://leetcode.com/problems/search-in-a-binary-search-tree/
*/


TreeNode *searchBST(TreeNode *root, int val) {
    // base case
    if(!root)
        return NULL;
    // condition check
    if(root->val == val)
        return root;
    // recursive calls: narrow down the search space
    if(val < root->val)
        return searchBST(root->left, val);
    else    
        return searchBST(root->right, val);
}