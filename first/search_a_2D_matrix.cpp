class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        if (m == 0) {
            return false;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return false;
        }
        int up = 0;
        int bottem = m-1;
        int middle;
        if (target < matrix[0][0]) {
            return false;
        }
        while (up!= bottem) {
            middle = (up+bottem+1)/2;
            if (matrix[middle][0] > target) {
                bottem = middle-1;
            } else if (matrix[middle][0] < target) {
                up = middle;
            } else {
                return true;
            }
        }
        if (bottem < m && target > matrix[bottem][0]) {
            up = bottem;
        }
        int left = 0;
        int right = n-1;
        while (left <= right) {
            middle = (left+right)/2;
            if (matrix[up][middle] == target) {
                return true;
            } else if (matrix[up][middle] > target) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        return false;
    }
};
