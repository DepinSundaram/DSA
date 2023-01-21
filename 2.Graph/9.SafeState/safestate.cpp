/*
Problem Statement: A directed graph of V vertices and E edges is given in the form of an adjacency list adj. 
Each node of the graph is labeled with a distinct integer in the range 0 to V – 1.
A node is a terminal node if there are no outgoing edges. 
A node is a safe node if every possible path starting from that node leads to a terminal node.
You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
*/

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Solution
{

    	bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[],  int check[]) {
		vis[node] = 1;
		pathVis[node] = 1;
		check[node] = 0;
		// traverse for adjacent nodes
		for (auto it : adj[node]) {
			// when the node is not visited
			if (!vis[it]) {
			if (dfsCheck(it, adj, vis, pathVis, check) == true) {
					check[node] = 0;
					return true;
				}

			}
			// if the node has been previously visited
			// but it has to be visited on the same path
			else if (pathVis[it]) {
				check[node] = 0;
				return true;
			}
		}
		check[node] = 1;
		pathVis[node] = 0;
		return false;
	}
public:


/*
SafeNodeBFS
Time Complexity: O(V+E)+O(N*logN), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm.
Extra O(N*logN) for sorting the safeNodes array, where N is the number of safe nodes.

Space Complexity: O(N) + O(N) + O(N) ~ O(3N), O(N) for the indegree array, O(N) for the queue data structure used in BFS(where N = no.of nodes), and extra O(N)
for the adjacency list to store the graph in a reversed order.


eventualSafeNodesDFS
Time Complexity: O(V+E)+O(V), where V = no. of nodes and E = no. of edges. There can be at most V components. So, another O(V) time complexity.

Space Complexity: O(3N) + O(N) ~ O(3N): O(3N) for three arrays required during dfs calls and O(N) for recursive stack space.
*/




	vector<int> eventualSafeNodesDFS(int V, vector<int> adj[]) {
		int vis[V] = {0};
		int pathVis[V] = {0};
		int check[V] = {0};
		vector<int> safeNodes;
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				dfsCheck(i, adj, vis, pathVis, check);
			}
		}
		for (int i = 0; i < V; i++) {
			if (check[i] == 1) safeNodes.push_back(i);
		}
		return safeNodes;
	}

    vector<int> SafeNodeBFS(int V, vector<int> adj[]) {

        // Reverse the link;
        vector<int> RevAdj[V];
		int indegree[V] = {0};
        for (int i = 0; i < V; i++) {
            // i -> itr
            // Do itr -> i;
            for (auto itr :  adj[i]) {
                RevAdj[itr].push_back(i);
                indegree[i]++;
            }
        }


        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        // BFS
        vector<int> safeNodes;
        while (q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for (auto links : RevAdj[node]) {
                indegree[links]--;
                if (indegree[links] == 0) { // push when 
                    q.push(links);
                }

            }
        }


        // Reverse as asked
        sort(safeNodes.begin(), safeNodes.begin());

        return safeNodes;
    }
};
int main()
{
    int V = 12;
    vector<int> adj[V] =  {{1}, {2}, {3, 4}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10},
		                  {8}, {9}};
    Solution sl;

    auto res = 

    return 0;
}
