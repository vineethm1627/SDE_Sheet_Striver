/*
    Problem Link: https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
*/

// helper function to merge 2 sorted lists
Node *mergeLists(Node *l1, Node *l2) {
    // base cases
    if(!l1)
        return l2;
    if(!l2)
        return l1;
    // recursive calls
    if(l1->data <= l2->data) {
        l1->bottom = mergeLists(l1->bottom, l2);
        return l1;
    }
    else {
        l2->bottom = mergeLists(l1, l2->bottom);
        return l2;
    }
}

Node *flatten(Node *root) {
    // base case
    if(!root || !root->next)
        return root;
    // recursive call
    return mergeLists(root, flatten(root->next));
}
