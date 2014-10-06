class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> results;
        if (matrix.size() == 0) return results;
        int left = 0;
        int right = matrix[0].size()-1;
        int up = 0;
        int down = matrix.size()-1;
        while (up <= down) {
            for (int j = left; j <= right; ++j) {
                results.push_back(matrix[up][j]);
            }
            up++;
            if (left <= right) {
                for (int i = up; i <= down; ++i) {
                    results.push_back(matrix[i][right]);
                }
                right--;
            }
            if (up <= down) {
                for (int j = right; j >= left; --j) {
                    results.push_back(matrix[down][j]);
                }
                down--;
            }
            if (left <= right) {
                for (int i = down; i >= up; --i) {
                    results.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return results;
    }
};