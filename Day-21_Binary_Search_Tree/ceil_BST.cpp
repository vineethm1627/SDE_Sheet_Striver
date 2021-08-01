/*
    Problem Link: https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1/?track=DSASP-BST&batchId=393
*/

int findCeil(Node *root, int key) {
    int ceil_val = -1;
    while(root) {
        if(root->data == key)
            return key;
        else if(root->data > key) {
            ceil_val = root->data;
            root = root->left;
        }
        else
            root = root->right;
    }
    return ceil_val;
}