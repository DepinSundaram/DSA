#include <iostream>
#include <vector>
#include <queue>

using namespace std;


void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

/*
Output: 0 1 4 2 3

Time Complexity: O(N) + O(2E), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes.

Space Complexity: O(3N) ~ O(N), Space for queue data structure visited array and an adjacency list
*/
vector<int>  bfs(vector<int> adj[])
{
    vector<int> bfs;
    vector<int> vis(5, 0);
    queue<int> q;
    vis[0] = 1;
    q.push(0);

    while(!q.empty()) {
        int top = q.front();
        q.pop();
        bfs.push_back(top);
        for (auto i : adj[top]) {
            if (vis[i] == 0) {
                q.push(i);
                vis[i] = 1;
            }
        }
    }
    return bfs;
}


/*
Output: 0 2 4 1 3 

Time Complexity: For an undirected graph, O(N) + O(2E), 
For a directed graph, O(N) + O(E), Because for every node we 
are calling the recursive function once, the time taken is O(N) and
2E is for total degrees as we traverse for all adjacent nodes.

Space Complexity: O(3N) ~ O(N),
Space for dfs stack space, visited array and an adjacency list.

*/

void Getdfs(vector<int> adj[], int node, vector<int>& bfs, vector<int>& vis)
{
    vis[node] = 1;
    bfs.push_back(node);

    for (auto it : adj[node]) {
        if (vis[it] == 0) {
            Getdfs(adj, it, bfs, vis);
        }
    }
}

vector<int> dfs(vector<int> adj[])
{
    vector<int> bfs;
    vector<int> vis(5, 0);
    int start = 0;
    Getdfs(adj, start, bfs, vis);

    return bfs;
}


int main()
{
    vector<int> adj[5];
    addEdge(adj, 0, 2); 
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);


    auto ans = dfs(adj);
    cout << "dfs : ";

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}