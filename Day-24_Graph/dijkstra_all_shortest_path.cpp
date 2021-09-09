/*
Problem Link: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1/
*/

#define pii pair<int, int>
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<bool> visited(V, false);
        vector<int> distance(V, INT_MAX); // initially mark all the distance to be infinity
        distance[S] = 0; // distance of source node from itself = 0
        priority_queue<pii, vector<pii>, greater<pii>> pq; // minHeap to get the node with least distance
        // pii -> {distance, node}
        pq.push({distance[S], S});
        while(!pq.empty()) {
            // get the current node with min distance
            int u = pq.top().second;
            pq.pop();
            visited[u] = true;
            // perform the relax operation by going through unvisited adjacent nodes
            for(auto v : adj[u]) {
                // v -> {node, weight}
                if(!visited[v[0]] && distance[u] + v[1] < distance[v[0]]) {
                    distance[v[0]] = distance[u] + v[1];
                    // push this node in the pq
                    pq.push({distance[v[0]], v[0]});
                }
            }
        }
        return distance;
    }
};