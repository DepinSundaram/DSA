#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
Time Complexity: O(NxM + NxMx4) ~ O(N x M)

For the worst case, all of the pixels will have the same colour, so DFS function will be called for (N x M) nodes and for every node we are traversing for 4 neighbours, so it will take O(N x M x 4) time.

Space Complexity: O(N x M) + O(N x M)

O(N x M) for copied input array and recursive stack space takes up N x M locations at max. 
*/
class Solution
{
    void DFS(int srow, int scol, vector<vector<int> >& ans, vector<vector<int> >& image, int newColor,int delRow[], int delCol[], int iniColor) {
        // Color the source
        ans[srow][scol] = newColor;
        int n = image.size();
        int m = image[0].size();

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int nrow = srow + delRow[i];
                int ncol = scol + delCol[i];
                // check for valid coordinate 
                // then check for same initial color and unvisited pixel

                if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && 
                image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
                    DFS(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor);
                }
            }
        }
    }

public:
    vector<vector<int> > floodFill(vector<vector<int> >& image, int row, int col, int newColor) {
        vector<vector<int> > Newimage = image;
        int n = image.size();
        int m = image[0].size();
        int iniColor = image[row][col]; 

        // delta row and delta column for neighbours
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        DFS(row, col, Newimage, image, newColor, delRow, delCol, iniColor);
    }
};
int main(){
		
	vector<vector<int> > image{
	    {1,1,1},
	    {1,1,0},
	    {1,0,1}
	};
	
// sr = 1, sc = 1, newColor = 2  	
	Solution obj;
	vector<vector<int> > ans = obj.floodFill(image, 1, 1, 2);
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
	
	return 0;
}