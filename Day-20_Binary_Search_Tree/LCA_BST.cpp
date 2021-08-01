/*
    Problem Link: https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1
*/

Node *LCA(node *root, int n1, int n2) {
    // case-1: both lie in the right subtree
    if(min(n1, n2) > root->data)
        return LCA(root->right, n1, n2);
    // case-2: both lie in the left subtree
    if(max(n1, n2) < root->data)
        return LCA(root->left, n1, n2);
    // one lies on the left and another on right
    return root;
}