#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

/*
Time Complexity: O(V+E)+O(V) , where V = no. of nodes and E = no. of edges. There can be at most V components. So, another O(V) time complexity.

Space Complexity: O(2N) + O(N) ~ O(2N): O(2N) for two visited arrays and O(N) for recursive stack space.
*/


class Solution
{
    bool DFS(int node, vector<int> adj[], vector<int> vis[],  vector<int> pathVis[]) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto itr : adj[node]) {
            if (!vis[itr]) {
                if (DFS(itr, adj, vis, pathVis) == true) return true;
            } else
            if (pathVis[itr]) {
                return true;
            }
        }


        pathVis[node] = 0;
        return false;
    }
    public:
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pathVis[V] = {0};

        for (int i = 0; i < V; i++) {
            if (!vis[V]) {
                if (DFS(int i, adj, vis, pathVis)) {
                    return true;
                }
            }
        }

        return true;
    }
};

int main() {

	// V = 11, E = 11;
	vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	int V = 11;
	Solution obj;
	bool ans = obj.isCyclic(V, adj);

	if (ans)
		cout << "True\n";
	else
		cout << "False\n";

	return 0;
}