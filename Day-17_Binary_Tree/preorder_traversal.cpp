/*
    Problem Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
*/

vector<int> preorderTraversal(TreeNode *root) {
    // base case
    if(!root)
        return {};
    
    vector<int> results;
    stack<TreeNode*> s;
    // NLR: so the root node is printed first
    s.push(root);

    // we follow level order traversal
    while(!s.empty()) {
        TreeNode *front = s.top();
        s.pop();
        // add the data in the results
        results.push_back(front->val);
        // add the right child first before the left one
        // owing to LIFO rule, the left child will be popped first
        if(front->right)
            s.push(front->right);
        if(front->left)
            s.push(front->left);
    }
    return results;
}