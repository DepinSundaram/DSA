#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
	vector<vector<int>> ans = obj.floodFill(image, 1, 1, 2);
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
	
	return 0;
}