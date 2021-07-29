/*
    Problem Link: https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
*/

vector<int> bottomView(Node *root) {
    // base case
    if(!root)
        return {};
    
    queue<pair<Node*, int>> q; {node, horizontal distance from the root node}
    q.push({root, 0});
    map<int, int> m; // {horizontal distance from the root node}
    // perform BFS: level order traversal
    while(!q.empty()) {
        Node *front = q.front().first;
        int distance = q.front().second;
        q.pop();

        // overwrite the map
        m[distance] = front->data;
        // insert the children in the queue if they exist
        if(front->left)
            q.push({front->left, distance - 1});
        if(front->right)
            q.push({front->right, distance + 1});
    }
    // store node data values in the vector
    vector<int> results;
    for(auto &p : m)
        results.push_back(p.second);
    
    return results;
}