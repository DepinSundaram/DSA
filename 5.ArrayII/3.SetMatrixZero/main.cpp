#include <iostream>
#include <vector>
#include <map>
using namespace std;
void markRow(vector<vector<int>>& matrix, int row, int col, int colInd) {
    for (int i = 0; i < row; i ++) {
        if (matrix[i][colInd] != 0) {
            matrix[i][colInd] = -1;
        }
    }
}

void markCol(vector<vector<int>>& matrix, int row, int col, int rowInd) {
    for (int i = 0; i < col; i ++) {
        if (matrix[rowInd][i] != 0) {
            matrix[rowInd][i] = -1;
        }
    }
}

/*
Time Complexity: O((N*M)*(N + M)) + O(N*M), where N = no. of rows in the matrix and M = no. of columns in the matrix.
Reason: Firstly, we are traversing the matrix to find the cells with the value 0. It takes O(N*M). Now, whenever we find any such cell we mark that row and column with -1. This process takes O(N+M). So, combining this the whole process, finding and marking, takes O((N*M)*(N + M)).
Another O(N*M) is taken to mark all the cells with -1 as 0 finally.

Space Complexity: O(1) as we are not using any extra space.
*/
vector <vector<int>> zeroMatrixBF(vector<vector<int>>& matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == 0) {
                markRow(matrix, row, col, i);
                markCol(matrix, row, col, j);

            }
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }
return matrix;
}

vector<vector<int>> zeroMatrixOptimized(vector<vector<int>> &matrix, int r, int c) {
    vector <int> row(r, 0);
    vector <int> col(c, 0);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }


    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int row, int col) {
    // row == > matrix[..][0]
    // col == matrix[0][..]
    int col0 = 1;
    // 1. traverse matrix and mar 1row and col accordingly;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0; // mark i row

                if (j != 0) {
                    matrix[0][j] = 0;
                } else {
                    col0 = 0;
                }
            }
        }
    }

    // 2 Mart with 0 from (1,1, row-1, col-1)

    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }


    //step 3: Finally mark the 1st col & then 1st row:

    if (matrix[0][0] == 0) {
        for (int j = 0; j < col; j++) {
            matrix[0][j] = 0;
        }
    }

    if (col0 == 0) {
        for (int j = 0; j < row; j++) {
            matrix[j][0] = 0;
        }
    }
return matrix;
}
int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, row, col);

    cout << "The Final matrix is: \n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}