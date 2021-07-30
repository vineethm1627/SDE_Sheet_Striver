/*
    Problem Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
*/

vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    // edge case
    if(!root)
        return {};
    
    vector<vector<int>> results;
    queue<TreeNode*> q;
    q.push(root); // push the root node
    bool left_to_right = true;
    // perform BFS: level order traversal
    while(!q.empty()) {
        int n = q.size();
        vector<int> inter(n);

        for(int i = 0; i < n; i++) {
            TreeNode *front = q.front();
            q.pop();
            // find the position to fill the node's value
            int idx = left_to_right ? i : n - 1 - i;
            // insert the node data value
            inter[idx] = front->val;
            // add the children in the queue if they exist
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
        // reverse the order for the next level
        left_to_right = !left_to_right;
        results.push_back(inter);
    }
    return results;
}