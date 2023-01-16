#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
SC : O(N^2) + O(N^2) ~ O(N^2)
    visited arr +  queue if all data need to be traversed

TC: O(N^2)
*/


class Solution {
    void BFS(vector<vector<char> >& grid, int row, int col, vector<vector<int> >& visited) {
        visited[row][col] = 1;
        queue<pair<int, int> > q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // travers 8 neighbours https://www.youtube.com/watch?v=muncqlKJrH0&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=8

            for (int delrow = -1 ; delrow <= 1; delrow++) {
                for (int delcol = -1; delcol <= 1; delcol++) {
                    int nrow = row + delrow;
                    int ncol = col + delcol;

                    if (nrow < n && nrow >=0 &&
                        ncol < m && ncol >= 0 &&
                        grid[nrow][ncol] == '1' && !visited[nrow][ncol]) {
                            visited[nrow][ncol] = 1;
                            q.push({nrow, ncol});
                        }
                }
            }
        }

    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char> >& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int> > visited(n , vector<int>(m , 0));
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    BFS(grid, i, j, visited);
                    count++;
                }
            }
        }
        return count;
    }
};

