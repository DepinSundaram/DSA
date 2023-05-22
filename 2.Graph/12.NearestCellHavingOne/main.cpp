#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();


        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> q;

        for (int i = 0 ; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                } else {
                    vis[i][j] = 0;
                }
            }
        }


    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int step = q.front().second;
        q.pop();
        dist[row][col] = step;

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int mcol = col + dcol[i];

            if (nrow >= 0 && nrow < n && mcol >= 0 && mcol < m
            && vis[nrow][mcol] == 0) {
                vis[nrow][mcol] = 1;
                q.push({{nrow, mcol}, step+1});
            }
        }
    }


        return dist;
    }
};

int main(){
    vector<vector<int>>grid{
        {0,1,1,0},
        {1,1,0,0},
        {0,0,1,1}
    };
	
	Solution obj;
	vector<vector<int>> ans = obj.nearest(grid);
		
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
	
	return 0;
}