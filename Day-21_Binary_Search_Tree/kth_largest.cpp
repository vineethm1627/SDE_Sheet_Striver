/*
    Problem Link: https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
*/

// reverse iterative inorder traversal using stack
int kthLargest(Node *root, int k) {
    stack<Node*> s;
    while(!s.empty() || root) {
        // reach the rightmost node
        while(root) {
            s.push(root);
            root = root->right;
        }
        // pop the rightmost node
        root = s.top();
        s.pop();
        // condition check
        if(--k == 0)
            return root->data;
        // move to the left subtree
        else    
            root = root->left;
    }
    return -1;
}