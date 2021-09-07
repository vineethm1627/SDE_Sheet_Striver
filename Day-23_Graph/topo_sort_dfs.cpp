/*
    Topological Sorting using BFS.
    Task dependencies.
    Topological sorting for a graph is not possible if the graph is not a DAG.
    It is a linear ordering of the vertices such that for every directed edge u, v,
    vertix u comes before v in the ordering.
    A DAG is a directed graph without any cycle.
*/

class Solution
{
	public:
	// helper function to perform dfs
	void dfs_helper(int node, vector<bool> &visited, stack<int> &st, vector<int> adj[]) {
	    // mark the current node as visited
	    visited[node] = true;
	    // init dfs calls over the unvisited adjacent nodes
	    for(int &nbr : adj[node]) {
	        if(!visited[nbr])
	            dfs_helper(nbr, visited, st, adj);
	    }
	    // push the current node after all its adjacent neighbor nodes are pushed
	    st.push(node);
	}
	
	// Function to return list containing vertices in Topological order.
	// topological sort using DFS, u -> v (we will push v in the stack before u) for all edges
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int> st;
	    vector<bool> visited(V, false);
	    // init dfs call over each disconnected component
	    for(int i = 0; i < V; i++) {
	        if(!visited[i])
	            dfs_helper(i, visited, st, adj);
	    }
	    vector<int> results;
	    while(!st.empty()) {
	        results.push_back(st.top());
	        st.pop();
	    }
	    return results;
	}
};