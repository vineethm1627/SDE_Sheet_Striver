/*
    Problem Link: https://leetcode.com/problems/same-tree/
*/

bool isSame(TreeNode *p, TreeNode *q) {
    // base case
    if(!p && !q)
        return true;
    if(!p || !q)
        return false;
    if(p->val != q->val)
        return false;
    // recursive calls
    return isSame(p->left, q->left) && isSame(p->right, q->right);
}