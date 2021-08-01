/*
   Problem Link: https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1# 
*/

void findPreSuc(Node *root, Node *&pre, Node *&succ, int key) {
    // base case
    if(!root)
        return;
    // successor candidate
    if(root->key > key) {
        succ = root;
        // key lies in the left subtree
        return findPreSuc(root->left, pre, succ, key);
    }
    // predecessor candidate
    else if(root->key < key) {
        pre = root;
        // key lies in the right subtree
        return findPreSuc(root->right, pre, suc, key);
    }
    // both successor and predecessor candidates
    else {
        // recursive calls on both sides
        if(root->left)
            findPreSuc(root->left, pre, suc, key);
        if(root->right)
            findPreSuc(root->right, pre, suc, key);
    }
}