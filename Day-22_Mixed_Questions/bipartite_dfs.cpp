/*
    Problem Link: https://practice.geeksforgeeks.org/problems/bipartite-graph/1
*/

class Solution {
public:
    /*
        bipartite graph is a graph that can be colored with exactly 2 colors
        such that no 2 adjacent nodes have the same color.
    */
    // helper function using dfs
    bool check_bipartite(int node, vector<int> adj[], vector<int> &color) {
        // for the source node, we start with color 1
        if(color[node] == -1)
            color[node] = 1;
        
        // make dfs calls on the adjacent nodes
        for(int &nbr : adj[node]) {
            // if the node is prev. unvisited, color it with opposite color
            if(color[nbr] == -1) {
                // first color and then make the recursive call
                color[nbr] = 1 - color[node];
                if(!check_bipartite(nbr, adj, color)) 
                    return false;
            }
            // same color for 2 adjacent nodes: not bipartite 
            else if(color[nbr] == color[node])
                return false;
        }
        return true;
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V, -1);
	    // init dfs call for each disconnected component
	    for(int i = 0; i < V; i++) {
	        if(color[i] == -1) {
	            if(!check_bipartite(i, adj, color))
	                return false;
	        }
	    }
	    return true;
	}

};