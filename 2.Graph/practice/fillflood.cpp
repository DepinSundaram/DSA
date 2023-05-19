#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
2 2 2
2 2 0 
2 0 1
Time Complexity: O(NxM + NxMx4) ~ O(N x M)

For the worst case, all of the pixels will have the same colour, so DFS function will be called for (N x M) nodes and for every node we are traversing for 4 neighbours, so it will take O(N x M x 4) time.

Space Complexity: O(N x M) + O(N x M)

O(N x M) for copied input array and recursive stack space takes up N x M locations at max. 


*/
void dfs(int sr, int sc, int newcolor, int initColor, vector<vector<int> >& image, vector<vector<int> >& ans,
    int drow[], int dcol[])
{
    ans[sr][sc] = newcolor;
    int n = image.size();
    int m = image[0].size();

    for (int i = 0; i < 4; i++) {
        int nrow = sr + drow[i];
        int ncol = sc + dcol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
            if (image[nrow][ncol] == initColor && ans[nrow][ncol] != newcolor) {
                dfs(nrow, ncol, newcolor, initColor, image, ans, drow, dcol);
            }
        }
    }
}


vector<vector<int> > FillFlood(int sr, int sc, int newcolor, vector<vector<int> > &image)
{
    vector<vector<int> > ans = image;
    int initcolor = image[sr][sc];
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    dfs(sr, sc, newcolor, initcolor, image, ans, drow, dcol);
    return  ans;
}

int main()
{

    vector<vector<int> > image = 
    {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    auto ans = FillFlood(1, 1, 2, image); // new color is 2 sr = 1, sc =1

    for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
}