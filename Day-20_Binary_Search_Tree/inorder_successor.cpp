/*
    Problem Link: https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1
*/

// successor has a value just greater than the node x
Node *inOrderSuccessor(Node *root, int x) {
    Node *succ = NULL;
    while(root) {
        if(root->data > x->data) {
            succ = root;
            // x will lie in the left subtree
            root = root->left;
        }
        else    
            root = root->right;
    }
    return succ;
}