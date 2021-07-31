/*
    Problem Link: https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1
*/

struct Node {
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

struct LinkedList {
    Node *head;
    Node *tail;
};

LinkedList flatten(Node *root) {
    // base case
    LinkedList dll;
    if(!root) {
        // init an empty list
        dll.head = dll.tail = NULL;
        return dll;
    }
    // case-1: left node
    if(!root->left && !root->right) {
        dll.head = dll.tail = root;
        return dll;
    }
    // case-2: only left subtree exists
    else if(root->left && !root->right) {
        // convert left subtree into DLL
        LinkedList left = flatten(root->left);
        // connect the tail of the left subtree with the root node
        left.tail->right = root;
        root->left = left.tail;
        // update the tail to be the root node
        dll.tail = root;
        // update the head to be the head of the left subtree
        dll.head = left.head;

        return dll;
    }
    // case-3: only right subtree exists
    else if(!root->left && root->right) {
        // convert right subtree into DLL
        LinkedList right = flatten(root->right);
        // connect the head of the right subtree with the root node
        right.head->left = root;
        root->right = right.head;
        // update the head to be the root node
        dll.head = root;
        // update the tail to be the tail of the right subtree
        dll.tail = right.tail;

        return dll;
    }
    // case-4: both subtrees exist
    else {
        // convert left subtree into DLL
        LinkedList left = flatten(root->left);
        // convert right subtree into DLL
        LinkedList right = flatten(root->right);
        // connect tail of left subtree with root node
        left.tail->right = root;
        root->left = left.tail;
        // connect head of the right subtree with root node
        right.head->left = root;
        root->right = right.head;
        // update head to be the head of the left subtree
        dll.head = left.head;
        // update tail to be the tail of the right subtree
        dll.tail = right.tail;
        
        return dll;
    }
}

Node *bToDLL(Node *root) {
    return flatten(root).head;
}