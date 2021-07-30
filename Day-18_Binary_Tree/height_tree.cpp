/*
    Problem Link: https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
*/

int height(Node *root) {
    // base case
    if(!root)
        return 0;
    // recursive calls
    int left_h = height(root->left);
    int right_h = height(root->right);

    return max(left_h, right_h) + 1;
}