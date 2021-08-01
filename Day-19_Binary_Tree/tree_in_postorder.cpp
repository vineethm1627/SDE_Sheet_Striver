/*
    Problem Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
*/

/*
Steps:
    1) iteratively pick one element from postorder array and create a node
    2) search for the index of this element in inorder array
    3) make recursive call on left and right subtree
*/

// helper function to create the binary tree
TreeNode *build_helper(vector<int> &postorder, vector<int> &inorder, int start, int end, int &post_index) {
    // base case
    if(start > end)
        return NULL;
    // create node from postorder value
    TreeNode *root = new TreeNode(postorder[post_index]);
    // search for the index in the inorder vector
    int idx = -1;
    for(int i = start; i <= end; i++) {
        if(inorder[i] == postorder[post_index]) {
            idx = i;
            break;
        }
    }
    // decrease the index of the postorder vector
    post_index--;
    // recursive calls: right first (LRN) from right to left it is N->R->L
    root->right = build_helper(postorder, inorder, idx + 1, end, post_index);
    root->left = build_helper(postorder, inorder, start, idx - 1, post_index);

    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int n = postorder.size(), post_index = n - 1;
    // call to the helper function
    return build_helper(postorder, inorder, 0, n - 1, post_index);
}