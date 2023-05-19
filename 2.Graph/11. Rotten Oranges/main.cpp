#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
Output: 1

Time Complexity: O(NxM + NxMx4) ~ O(N x M), 
For the worst case, all of the cells will have fresh oranges, 
so the BFS function will be called for (N x M) nodes and for every node, we are traversing for 4 neighbours, it will take O(N x M x 4) time.

Space Complexity ~ O(N x M), O(N x M) for copied input array
and recursive stack space takes up N x M locations at max. 
*/
int OrangeRottins(vector<vector<int>> &oranges)
{
    int nr = oranges.size();
    int mc = oranges[0].size();


    queue<pair <pair<int, int>, int> > q;
    int vis[nr][mc];
    int countFresh = 0;

    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < mc; j++) {
            if (oranges[i][j] == 2) {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }else {
                vis[i][j] = 0;
            }

            if (oranges[i][j] == 1) {
                countFresh++;
            }
        }
    }

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    int cnt = 0;
    int tm = 0;
    while(!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >=0 && nrow < nr && ncol < mc && ncol >=0) {
                if (vis[nrow][ncol] == 0 && oranges[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t+1});

                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }
    }

    if (cnt !=countFresh) {
        return -1;
    }

    return tm;

}

int main()
{

    vector<vector<int>> oranges =
    {
        {0, 1, 2},
        {0, 1, 2},
        {2, 1, 1}
    };

    int ans = OrangeRottins(oranges);

    cout << ans;

}