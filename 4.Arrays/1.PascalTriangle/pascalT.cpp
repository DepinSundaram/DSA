#include <bits/stdc++.h> 

/*
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
*/


class Solution {
public:
/**
 * The function generates Pascal's triangle up to a given number of rows and returns it as a vector of
 * vectors.
 * 
 * @param numRows The input parameter `numRows` is an integer that specifies the number of rows to
 * generate in the Pascal's triangle.
 * 
 * @return The function `generate` returns a 2D vector of integers, where each row represents a row of
 * Pascal's triangle and each element in the row represents a value in that row. The number of rows in
 * the triangle is determined by the input parameter `numRows`.
 */
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > r(numRows);
        for (int i = 0; i < numRows; i++) {
            r[i].resize(i+1);
            r[i][0] = r[i][i] = 1;

            for (int j = 1; j < i; j++) {
                r[i][j] = r[i-1][j-1] + r[i-1][j];
            }
        }

        return r;
    }
};


int main()
{
    int num = 5;
    Solution a;
    auto pt = a.generate(num);
    for (auto v : pt) {
        for (auto i : vec) {
            std::cout << i;
        }
        std::endl;
    }
}