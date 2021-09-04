/*
    Problem Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
*/

class Solution {
  public:
    // dfs helper function to find cycle
    bool checkForCycle(int node, int parent, vector<bool> &visited, vector<int> adj[]) {
        // mark the current node as visited
        visited[node] = true;
        for(int &nbr : adj[node]) {
            // if nbr is unvisited, init a dfs call
            if(!visited[nbr]) {
                if(checkForCycle(nbr, node, visited, adj))
                    return true;
            }
            // nbr = parent means it is the adjacent node (no cycle as such)
            else if(nbr != parent)
                return true;
        }
        return false;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(checkForCycle(i, -1, visited, adj))
                    return true;
            }
        }
        return false;
    }
};