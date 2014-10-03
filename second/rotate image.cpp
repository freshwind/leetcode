#include "stdlib.h"

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int row_num = matrix.size();
        if (row_num < 1) return;
        int col_num = matrix[0].size();
        int temp;
        for (int i = 0; i < row_num/2; ++i) {
            for (int j = i; j < col_num-i-1; ++j) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[row_num-j-1][i];
                //m[0][0] = m[2][0]
                //m[0][1] = m[1][0]
                matrix[row_num-j-1][i] = matrix[col_num-i-1][row_num-j-1];
                //m[2][0] = m[2][2]
                //m[1][0] = m[2][1]
                matrix[col_num-i-1][row_num-j-1] = matrix[j][col_num-i-1];
                //m[2][2] = m[0][2]
                //m[2][1] = m[1][2]
                matrix[j][col_num-i-1] = temp;
                //m[0][2] = m[0][0]
                //m[1][2] = m[0][1]
            }
        }
    }

    // 1 2
    // 3 4
// 1 3
// 2 4
// 3 1
// 4 2
    void rotate2(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n/2; ++j) {
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }
    }
    // 3 1
    // 4 2
};

int main() {
    Solution sol;
    vector<vector<int> > matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12},{13, 14, 15, 16}};
    sol.rotate2(matrix);
    print(matrix);
}

// 1 2 3
// 4 5 6
// 7 8 9

// 7 4 1
// 8 5 2
// 9 6 3