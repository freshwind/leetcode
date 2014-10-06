class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        int up = 0;
        int down = matrix.size()-1;
        if (up > down) return result;
        int left = 0;
        int right = matrix[0].size()-1;
        while (up <= down) {
            for (int i = left; i <= right; ++i) {
                result.push_back(matrix[up][i]);
            }
            up++;
            if (left <= right) {
                for (int i = up; i <= down; ++i) {
                    result.push_back(matrix[i][right]);
                }
            }
            right--;
            if (up <= down) {
                for (int i = right; i >= left; --i) {
                    result.push_back(matrix[down][i]);
                }
            }
            down--;
            if (left <= right) {
                for (int i = down; i >= up; --i) {
                    result.push_back(matrix[i][left]);
                }
            }
            left++;
        }
        return result;
    }
};
