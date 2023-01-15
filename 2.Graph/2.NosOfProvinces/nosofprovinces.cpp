#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Time Complexity: O(N) + O(V+2E), Where O(N) is for outer loop and inner loop runs in total a single DFS over entire graph, and we know DFS takes a time of O(V+2E). 

Space Complexity: O(N) + O(N),Space for recursion stack space and visited array.
*/
class Solution
{
    void DFS(int node, vector<int> adj[], int visited[])
    {
        visited[node] = 1;
        for (auto i : adj[node]) {
            if (!visited[i]) {
                DFS(i, adj, visited);
            }
        }
    }
public:
    int NoOfProvinecs(int V, vector<vector<int> > adjMatrix) {
        vector<int> adjList[V];

        // Prepare adj list from matrix
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adjMatrix[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);

                }
            }
        }

        int visited[V]{0};
        int cnt = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                cnt++;
                DFS(i, adjList, visited);
            }
        }

    }
};