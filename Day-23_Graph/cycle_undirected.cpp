/*
    Problem Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
*/

bool bfs(vector<int> adj[], int source, int V, vector<bool> &visited) {
    queue<int> q;
    q.push(source);
    // mark the source node as visited
    visited[source] = true;
    vector<int> parent(V, -1);

    // apply BFS
    while(!q.empty()) {
        int front = q.front();
        q.pop();

        // visit the neighbours of this node
        for(int &nbr : adj[front]) {
            if(!visited[nbr]) {
                visited[nbr] = true;
                parent[nbr] = front;
                q.push(nbr);
            }
            else if(parent[front] != nbr)
                return true;
        }
    }
    return false;
}

// the graph could contain disconnected components as well
bool isCycle(int V, vector<int> adj[]) {
    // initially mark all the nodes as unvisited
    vector<bool> visited(V, false);
    // go through each node and call BFS on each unvisited node
    for(int i = 0; i < V; i++) {
        // cycle is detected
        if(!visited[i] && bfs(adj, i, V, visited))
            return true;
    }
    return false;
}
