#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
Create adj list for graph
cin >> V >> E; vertex and edges
vector<int> adj[V];

for (int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
DFS:
Time Complexity: For an undirected graph, O(N) + O(2E), For a directed graph, O(N) + O(E), 
Because for every node we are calling the recursive function once, the time taken is O(N) and 2E is for total degrees as we traverse for all adjacent nodes.
DFS takes a time of O(V+2E). 

Space Complexity: O(3N) ~ O(N), Space for dfs stack space, visited array and an adjacency list.

BFS:
Time Complexity: O(N) + O(2E), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes.

Space Complexity: O(3N) ~ O(N), Space for queue data structure visited array and an adjacency list

*/
class Solution {
  private: 
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
        vis[node] = 1;
        ls.push_back(node);
        // traverse all its neighbours
        for(auto i : adj[node]) {
            if (!vis[i]) { // if the neighbour is not visited

                dfs(i, adj, vis, ls);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        int start = 0;
        // create a list to store dfs
        vector<int> ls; 
        // call dfs for starting node
        dfs(start, adj, vis, ls); 
        return ls; 
    }

    std::vector<int> BFSGrapth(int V, std::vector<int> adj[])  {
        std::vector<int> BFSOrder;
        std::vector<int> vis(V, 0);
        vis[0] = 1;
        queue<int> q;
        // push the initial starting node 
        q.push(0); 

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            BFSOrder.push_back(node);
            for (auto i : adj[node]) {
                if (!vis[i]) {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }

        return BFSOrder;
    }
};



void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() 
{
    vector<int> adj[6]; // array of vector<int>
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);
    Solution sl;
    vector <int> ans = sl.BFSGrapth(5, adj);
    printAns(ans);

    return 0;
}


