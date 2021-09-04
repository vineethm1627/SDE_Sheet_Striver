/*
    Problem Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // helper function to detect cycle using dfs
    bool checkForCycle(int node, vector<bool> &visited, vector<bool> &stack_path, vector<int> adj[]) {
        // mark the current node as visited
        visited[node] = true;
        // add the node in the stack path, indicates it is a part of the current path
        stack_path[node] = true;

        for(int &nbr : adj[node]) {
            // check for back-edge
            if(stack_path[nbr])
                return true;
            // init dfs call for unvisited nodes
            else if(!visited[nbr]) {
                if(checkForCycle(nbr, visited, stack_path, adj))
                    return true;
            }
        }
        // when we leave the node, it is no longer a part of the current path
        stack_path[node] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> stack_path(V, false);

        // init a dfs call on each unvisited node (disconnected component)
        for(int i = 0; i < V; i++) {
            if(checkForCycle(i, visited, stack_path, adj))
                return true;
        }
        return false;
    }
};

int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}