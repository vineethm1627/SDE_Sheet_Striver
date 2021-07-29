/*
    Problem Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
*/

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> results;
    stack<TreeNode*> s;

    // LNR
    while(!s.empty() || root) {
        // push all the left nodes
        while(root) {
            s.push(root);
            root = root->left;
        }
        // the last leftmost node is taken into account
        root = s.top();
        s.pop();
        results.push_back(root->val);
        // move to the right subtree of the current root node
        root = root->right;
    }
    return results;
}