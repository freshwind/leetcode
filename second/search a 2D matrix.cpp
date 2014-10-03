class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int start = 0;
        int end = m*n-1;
        int median;
        int i,j;
        while (start <= end) {
            median = (start+end)/2;
            i = median/n;
            j = median%n;
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                end = median-1;
            } else {
                start = median+1;
            }
        }
        return false;
    }
};

