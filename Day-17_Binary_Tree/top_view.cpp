/*
    Problem Link: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
*/

// function to return list of nodes from left to right in Binary tree
vector<int> topView(Node *root) {
    // BFS level order traversal
    queue<pair<Node*, int>> q; // {node, horizontal distance from the root node}
    q.push({root, 0});
    map<int, int> m; // {horizontal distance from the root node, node value}
    // find the first encountered node at each vertical strips ie. horizontal distances from the root node
    while(!q.empty()) {
        Node *front = q.front().first;
        int distance = q.front().second;
        q.pop();

        // we dont have any node at this horizontal distance
        if(m.find(distance) == m.end())
            m[distance] = front->data;
        // add the children in the queue if they exist
        if(front->left)
            q.push({front->left, distance - 1});
        if(front->right)
            q.push({front->right, distance + 1});
    }
    // store the node data values
    vector<int> results;
    for(auto &p : m)
        results.push_back(p.second);
    
    return results;
}
