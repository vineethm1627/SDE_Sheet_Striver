/*  
    Problem Link: https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1#
*/

class Solution
{
	public:
	// Function to find number of strongly connected components in the graph.
	// from each node we can reach every other node in the SCC
	// dfs from the last node
	
	/*
	    Algorithm:
	        1. Sort all nodes in the order of finishing time ie. time of reach, when dfs call returns back
	        2. Transpose the graph ie. all the edges will get reversed.
	        3. Do the DFS according to the finishing time.
	*/
	// helper function to sort all the nodes in the order of finishing time.
	void dfs_helper(int node, stack<int> &st, vector<bool> &visited, vector<int> adj[]) {
	    // mark the current node as visited
	    visited[node] = true;
	    for(int &nbr : adj[node]) {
	        // make a dfs call for the unvisited neighbor
	        if(!visited[nbr])
	            dfs_helper(nbr, st, visited, adj);
	    }
	    // push the node once all the adjacent nodes are pushed first
	    st.push(node);
	}
	
	// helper function to do dfs
	void dfs(int node, vector<bool> &visited, vector<int> transpose[]) {
	    // mark the current node as visited
	    visited[node] = true;
	    for(int &nbr : transpose[node]) {
	        // make a dfs call for the unvisited neighbor
	        if(!visited[nbr])
	            dfs(nbr, visited, transpose);
	    }
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int> st;
        vector<bool> visited(V, false);
        // step-1: sort all nodes in the order of the finishing time
        // init dfs call for each disconnected component
        for(int i = 0; i < V; i++) {
            if(!visited[i])
                dfs_helper(i, st, visited, adj);
        }
        // step-2: take tranpose of the graph
        vector<int> transpose[V];
        for(int u = 0; u < V; u++) {
            visited[u] = false; // making it ready for the next step
            // edge from u to v
            for(int &v : adj[u]) {
                // edge from v to u
                transpose[v].push_back(u);
            }
        } 
        int count = 0;
        // step-3: do the dfs according to the finishing time.
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            
            if(!visited[node]) {
                dfs(node, visited, transpose);
                count++;
            }
        }
        return count;
    }
};