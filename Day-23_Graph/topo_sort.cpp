/*
    Topological Sorting using BFS.
    Task dependencies.
    Topological sorting for a graph is not possible if the graph is not a DAG.
    It is a linear ordering of the vertices such that for every directed edge u, v,
    vertix u comes before v in the ordering.
    A DAG is a directed graph without any cycle.
*/
#include <iostream>
#include <map>
#include <queue>
#include <cstring>
#include <list>
using namespace std;

template <class T>
class Graph {
        list<T> *l; // array of lists
        int V;
    public:
        Graph(int V) {
            this->V = V;
            // we have V number of linked lists
            l = new list<T>[V];
        }

        void addEdge(T x, T y) {
            l[x].push_back(y);
        }

        void topoSort() {
            // array of indegree
            int *indegree = new int[V];
            memset(indegree, 0, V * sizeof(int));
            // update the indegree by traversing edges
            for(int i = 0; i < V; i++) {
                for(auto const y : l[i]) {
                    indegree[y]++;
                }
            }
            // find nodes with 0 indegree
            queue<T> q;
            for(int i = 0; i < V; i++) {
                if(indegree[i] == 0)
                    q.push(i);
            }
            // apply BFS
            while(!q.empty()) {
                T front = q.front();
                cout << front << " ";
                q.pop();

                // iterate over the neighbours and reduce their indegree by 1
                for(auto const nbr : l[front]) {
                    indegree[nbr]--;
                    if(indegree[nbr] == 0)
                        q.push(nbr);
                }
            }
            
        }
};

int main() {

    Graph<int> g(6);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(4, 5);
    g.addEdge(3, 5);

    g.topoSort();

    return 0;
}