#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*

Time Complexity
O(N * M), where N is the number of rows and M is the number of columns in the matrix. 

 

Since we are traversing each element of the matrix just once, the time complexity of the above algorithm is O(N * M). 

Space Complexity
O(1)

 

We are not using any extra data structure, as we are updating the given matrix.
 Only constant extra space is required. Thus, the space complexity is O(1).*/
void rotateMatrixEnhance(vector<vector<int> > &mat, int n, int m)
{
    // Index of starting row and column
    int rowStart = 0, colStart = 0; 
    
    int previous, current; 

    while (rowStart < n && colStart < m) 
    { 
        // If we have rotated the whole matrix
        if (rowStart == n - 1 || colStart == m - 1)
        { 
            break; 
        }
        // Store the first element of next rown as this element will replace the first element of current row
        previous = mat[rowStart + 1][colStart]; 
        
        // Move elements of first row from the remaining rows
        for (int i = colStart; i < m; i++) 
        { 
            current = mat[rowStart][i]; 
            mat[rowStart][i] = previous; 
            previous = current; 
        } 
        rowStart++; 
  
        // Move elements of last column from the remaining columns 
        for (int i = rowStart; i < n; i++) 
        { 
            current = mat[i][m-1]; 
            mat[i][m-1] = previous; 
            previous = current; 
        } 
        m--; 
  
        // Move elements of last rowStart from the remaining rows 
        if (rowStart < n) 
        { 
            for (int i = m-1; i >= colStart; i--) 
            { 
                current = mat[n-1][i]; 
                mat[n-1][i] = previous; 
                previous = current; 
            } 
        } 
        n--; 
  
        // Move elements of first column from the remaining rows 
        if (colStart < m) 
        { 
            for (int i = n-1; i >= rowStart; i--) 
            { 
                current = mat[i][colStart]; 
                mat[i][colStart] = previous; 
                previous = current; 
            } 
        } 
        colStart++; 
    } 
} 
void rotateMatrixHelper(vector < vector < int > >&matrix, 
                  int rowStart, int colStart, int rowEnd, int colEnd) {

        // Base Condition
    if(rowStart >= rowEnd or colStart >= colEnd)
    {
        return; 
    }

    if (rowStart >= rowEnd - 1 || colStart >= colEnd - 1)
    { 
        return; 
    }

    int prev = matrix[rowStart + 1][colStart];
    int current;
    // move first row
    for (int i = colStart; i < colEnd; ++i) {
      current = matrix[rowStart][i];
      matrix[rowStart][i] = prev;
      prev = current;
    }

    rowStart++;

    // Move element of last col
    for (int i = rowStart; i < rowEnd; ++i) {
      current = matrix[i][colEnd -1];
      matrix[i][colEnd -1] = prev;
      prev = current;
    }
    colEnd--;

    // Move elements of last row from the remaining rows

    for (int i = colEnd -1 ; i >=colStart; --i) {
      current = matrix[rowEnd-1][i];
      matrix[rowEnd-1][i] = prev;
      prev = current;
    }
    rowEnd--;

    // Move elements of first column from the remaining rows 
 
    for (int i = rowEnd -1; i >=rowStart;i--) {
      current = matrix[i][colStart];
      matrix[i][colStart] = prev;
      prev = current;
    }

    colStart++;

    rotateMatrixHelper(matrix, rowStart, colStart, rowEnd, colEnd);
}
void rotateType2(vector < vector < int > >& matrix)


//https://www.codingninjas.com/codestudio/problems/981260
/*

    Time Complexity: O(N * M)
    Space Complexity: O(max(N, M))

    Time Complexity
O(N * M), where N is the number of rows and M is the number of columns in the matrix. 

 

Since we are traversing each element of the matrix just once, the time complexity of the above algorithm is O(N * M). 

Space Complexity
O(max(N, M)), where N is the number of rows and M is the number of columns in the matrix. 

 

We are making max(N/2, M/2) recursive calls and thus, stack space will be used. Hence, the space complexity is O(max(N, M)). 
ip:
[[1,2,3],
[4,5,6],
[7,8,9]]


o/p:
[[4,1,2],
 [7,5,3],
 [8,9,6]]
*/
{
    int row = matrix.size();
    int col = matrix[0].size();

    int colStart = 0;
    int colEnd = col;
    int rowStart = 0;
    int rowEnd = row;

	  rotateMatrixHelper(matrix, rowStart, colStart, rowEnd, colEnd);
}

/*

ip:
[[1,2,3],
[4,5,6],
[7,8,9]]
Rotated Image
7 4 1
8 5 2
9 6 3

Time Complexity: O(N*N) + O(N*N).One O(N*N) is for transposing the matrix and the other is for reversing the matrix.

Space Complexity: O(1).
*/
void rotate(vector < vector < int > >& matrix)
{
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i< n;++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
int main() {
  vector < vector < int >> arr;
  arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  rotateType2(arr);
  cout << "Rotated Image" << endl;
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
}
