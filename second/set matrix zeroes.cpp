class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row_num = matrix.size();
        if (row_num == 0) return;
        int col_num = matrix[0].size();
        bool first_row = false;
        bool first_col = false;
        for (int i = 0; i < col_num; ++i) {
            if (matrix[0][i] == 0) {
                first_row = true;
                break;
            }
        }
        for (int i = 0; i < row_num; ++i) {
            if (matrix[i][0] == 0) {
                first_col = true;
                break;
            }
        }
        for (int i = 1; i < row_num; ++i) {
            for (int j = 1; j < col_num; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < row_num; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < col_num; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j < col_num; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < row_num; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (first_row) {
            for (int j = 0; j < col_num; ++j) {
                matrix[0][j] = 0;
            }
        }
        if (first_col) {
            for (int i = 0; i < row_num; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
