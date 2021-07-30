/*
    Problem Link: https://leetcode.com/problems/diameter-of-binary-tree/
*/

/*
        diameter of tree = longest distance between any 2 nodes of the tree
        diameter could be the number of nodes between node of left subtree and node of right subtree.
        (inverted V shaped).
        We basically count the edges for the calculation of diameter.
        there are 3 cases:
            diameter passes through the root ==> height(left) + height(right)
            diameter lies in the left subtree ==> recursive function call
            diameter lies in the right subtree ==> recursive function call
*/
#define pii pair<int, int> // {height, diameter}

pii dia_helper(TreeNode *root) {
    // base case
    if(!root)
        return {0, 0};
    
    // recursive calls: postorder traversal
    pii left = dia_helper(root->left);
    pii right = dia_helper(root->right);
    // calculate the height of the current node
    int height = max(left.first, right.first) + 1;
    // case-1: dia passes through the root
    int option1 = left.first + right.first;
    // case-2: dia lies in the left subtree
    int option2 = left.second;
    // case-3: dia lies in the right subtree
    int option3 = right.second;
    // we choose the max of these 3 options
    int diameter = max({option1, option2, option3});
    
    return {height, diameter};
}

int diameterOfBinaryTree(TreeNode *root) {
    return dia_helper(root).second;
}