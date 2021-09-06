/*
    Problem Link: https://practice.geeksforgeeks.org/problems/bipartite-graph/1
*/

class Solution {
public:
    /*
        bipartite graph is a graph that can be colored with exactly 2 colors
        such that no 2 adjacent nodes have the same color.
    */
    // helper function using bfs
    bool check_bipartite(int source, vector<int> adj[], vector<int> &color) {
        queue<int> q;
        q.push(source);
        color[source] = 1;
        // visit the adjacent nodes and mark them with opposite color
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            
            for(int &nbr : adj[front]) {
                // check if not colored/ visited previously
                if(color[nbr] == -1) {
                    color[nbr] = 1 - color[front];
                    // push the neighbor in the queue
                    q.push(nbr);
                }
                // 2 adjacent nodes having the same color: not a bipartite
                else if(color[nbr] == color[front])
                    return false;
            }
        }
        return true;
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V, -1);
	    // init bfs call for each disconnected component
	    for(int i = 0; i < V; i++) {
	        if(color[i] == -1) {
	            if(!check_bipartite(i, adj, color))
	                return false;
	        }
	    }
	    return true;
	}

};