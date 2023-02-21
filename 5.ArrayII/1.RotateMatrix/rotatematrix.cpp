#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotateType2(vector < vector < int > >& matrix)
{
    
}

/*
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
  rotate(arr);
  cout << "Rotated Image" << endl;
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
}
