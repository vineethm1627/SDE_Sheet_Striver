/*
    Problem Link: https://leetcode.com/problems/binary-tree-postorder-traversal/
*/

vector<int> postorderTraversal(TreeNode *root) {
    // base case
    if(!root)
        return {};
    
    vector<int> results;
    stack<TreeNode*> s;
    s.push(root);
    // LRN: perform level order traversal
    while(!s.empty()) {
        TreeNode *front = s.top();
        // add the data in the results
        results.push_back(front->val);
        // NRL (reverse of LRN) is performed
        // owing to LIFO rule, we push the left child first
        if(front->left)
            s.push(front->left);
        if(front->right)
            s.push(front->right);
    }
    reverse(results.begin(), results.end());
    return results;
}