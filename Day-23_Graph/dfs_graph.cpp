/*
    Problem Link: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
*/

void dfs_helper(int node, vector<int> adj[], int V, vector<bool> &visited, vector<int> &results) {
    // base case
    if(visited[node])
        return;
    // mark the node as visited
    visited[node] = true;
    results.push_back(node);

    // recursive dfs calls over the nodes in the connected component
    for(int &nbr : adj[node]) {
        if(!visited[nbr])
            dfs_helper(nbr, adj, V, visited, results);
    }
}

//Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    vector<int> results;
    // init dfs calls on each disconnected component
    for(int i = 0; i < V; i++) {
        if(!visited[i])
            dfs_helper(i, adj, V, visited, results);
    }
    return results;
}