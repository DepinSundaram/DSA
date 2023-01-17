#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(N+M) {for the topological sort} + O(N+M) {for relaxation of vertices, each node and its adjacent nodes get traversed} ~ O(N+M).

Where N= number of vertices and M= number of edges.

Space Complexity:  O( N) {for the stack storing the topological sort} + O(N) {for storing the shortest distance for each node} + O(N) {for the visited array} + O( N+2M) {for the adjacency list} ~ O(N+M) .

*/
class Solution
{

   void topoSort(int node, vector<pair<int, int>> adj[], int vis[],  stack<int>& st) {
        vis[node] = 1;

        for (auto aj : adj[node]) {
            if (!vis[aj]) {
                int v = aj.first;
                topoSort(v, adj, vis, st);
            }
        }

        st.push(node)

   }
public:

    vector <int> shortestPath(int N, int M, vector<vector<int> >& edges) {

        // Prepare adj i -> {edge and wt}
        vector<pair<int, int>> adj[];

        for (int i = 0; i < M, i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back([v, wt]);
        }

        // A visited array is created with initially 
        // all the nodes marked as unvisited (0).
        int vis[N] = {0};

        //Now, we perform topo sort using DFS technique 
        //and store the result in the stack st.
        stack<int> st;

        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                topoSort(i, adj, vis, st);
            }
        }

        //Further, we declare a vector ‘dist’ in which we update the value of the nodes’
        //distance from the source vertex after relaxation of a particular node.

        int dis[N] = {1e9};

        dis[0] = 0;

        while(!st.empty()) {
            int node = st.top();
            st.pop();


            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;

                if (dis[v] > dis[node] + wt) {
                    dis[v] = dis[node] + wt;
                }
            }
        }


        for (int i = 0; i < N; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }

      return dist;

    }

};


int main() {

  int N = 6, M = 7;
  
  vector<vector<int>> edges= {{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};
  Solution obj;
  vector < int > ans = obj.shortestPath(N, M, edges);

  for (int i = 0; i < ans.size(); i++) {

    cout << ans[i] << " ";
  }

  return 0;

}