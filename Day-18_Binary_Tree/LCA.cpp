/*
    Problem Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
*/

TreeNode* LCA(TreeNode *root, TreeNode *p, TreeNode *q) {
    // base case
    if(!root)
        return NULL;
    
    // a node is its own ancestor
    if(root == p || root == q)
        return root;
    // recursive calls: postorder traversal
    TreeNode *left = LCA(root->left, p, q);
    TreeNode *right = LCA(root->right, p, q);
    // root is the LCA if both the children nodes are found
    if(left && right)
        return root;
    else if(left)
        return left;
    else    
        return right;
}