/*
    Problem Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
*/

vector<vector<int>> levelOrder(TreeNode *root) {
    // edge case
    if(!root)
        return {};
    
    vector<vector<int>> results;
    queue<TreeNode*> q;
    q.push(root); // push the root node
    // perform the level order traversal
    while(!q.empty()) {
       int n = q.size();
       vector<int> inter;
       while(n--) {
            TreeNode *front = q.front();
            q.pop();
            // push the data value in the vector
            inter.push_back(front->data);
            // add the children in the queue if they exist
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
       }
       results.push_back(inter);
    }
    return results;
}