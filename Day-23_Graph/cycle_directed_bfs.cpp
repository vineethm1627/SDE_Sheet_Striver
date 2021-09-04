/*
    Problem Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
*/

// topological sort is applicable for DAG only. So if topo sort is not possible then we can be sure there is a cycle.

class Solution {
public:
    bool isCyclic(int N, vector<int> adj[]) {
        queue<int> q;
        vector<int> indegree(N, 0);
        for(int u = 0; u < N; u++) {
            for(int &v : adj[u])
                indegree[v]++;
        }
        // push the nodes in the queue having an indegree of 0
        for(int i = 0; i < N; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        int count = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            // reduce the indegree of the neighbors by 1
            for(int &nbr : adj[node]) {
                if(--indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        // topological sort is complete, graph is acyclic
        if(count == N)
            return false;
        return true;
    }
};