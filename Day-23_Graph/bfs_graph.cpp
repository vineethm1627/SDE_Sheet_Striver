/*
    Problem Link: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
*/

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    // all nodes are initially not visited
    vector<bool> visited(V, false);
    vector<int> results;
    queue<int> q;
    // push the source node in the queue
    q.push(0);
    // mark the source node as visited
    visited[0] = true;

    while(!q.empty()) {
        int front = q.front();
        q.pop();
        results.push_back(front);
        // find the unvisited neighbours and add them in the queue
        for(int &nbr : adj[front]) {
            if(!visited[nbr]) {
                q.push(nbr);
                // mark the nbr as visited 
                visited[nbr] = true;
            }
        }
    }
    return results;
} 