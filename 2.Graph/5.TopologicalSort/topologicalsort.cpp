#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
 Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

Note: In topological sorting, node u will always appear before node v if there is a directed edge from node u towards node v(u -> v).

Time Complexity: O(V+E)+O(V), where V = no. of nodes and E = no. of edges. There can be at most V components. So, another O(V) time complexity.

Space Complexity: O(2N) + O(N) ~ O(2N): O(2N) for the visited array and the stack carried during DFS calls and O(N) for recursive stack space, where N = no. of nodes.

*/
class Solution
{

    vector<int> topoSortBFS(int V, vector<int> adj[]) {
        int indegree[V] = {0};
        for (int i = 0; i < V; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        vector<int> topo;
        for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    topo.push_back(it);
                }
            }

        }


    }
    void DFS(vector<int> adj[], int vis[], stack<int>& st, int i) {
        vis[i] = 1;
        for (auto adjL : adj[i]) {
            if (!vis[adjL]) {
                DFS(adj, vis, st, adjL);
            }
        }
        st.push(i);

    }
public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        int size = V;
        int vis[V] = {0};
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                DFS(adj, vis, st, i);
            }
        }

        vector<int> ans;
		while (!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}
		return ans;
    }
};

int main() {

	//V = 6;
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	Solution obj;
	vector<int> ans = obj.topoSort(V, adj);

	for (auto node : ans) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}