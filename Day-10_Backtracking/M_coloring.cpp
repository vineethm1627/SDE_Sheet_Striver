/*
    Problem Link: https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#
*/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int node, int color[], bool graph[101][101], int V, int col) {
    // check the colors of the adjacent node
    for(int k = 0; k < V; k++) {
        // k should not be the node itself
        // there should exist an edg betweent the node and its adjacent node
        // the adjacent node is marked with the same color: condition violated
        if(k != node && graph[k][node] == 1 && color[k] == col)
            return false;
    }
    return true;
}

bool solve(int node, int color[], int m, int V, bool graph[101][101]) {
    // base case
    if(node == V)
        return true;
    
    // try every color from 1 to m
    for(int i = 1; i <= m; i++) {
        // check if it is possible to color "node" with color "i"
        if(isPossible(node, color, graph, V, i)) {
            // mark the color of the node
            color[node] = i;
            // recursive call: if it is possible no need to unmark the color
            if(solve(node + 1, color, m, V, graph))
                return true;
            else
                // unmark the node for further iterations: backtracking
                color[node] = 0;
        }
    }
    return false;
}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int V) {
    // your code here
    int color[V] = {0};
    
    if(solve(0, color, m, V, graph))
        return true;
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
