class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int kM = grid.size();
        int kN = grid[0].size();
        vector<vector<int> > sum_grid(kM, vector<int>(kN));
        sum_grid[0][0] = grid[0][0];
        for (int m = 1; m < kM; m++) {
            sum_grid[m][0] = sum_grid[m-1][0] + grid[m][0];
        }
        for (int n = 1; n < kN; n++) {
            sum_grid[0][n] = sum_grid[0][n-1] + grid[0][n];
        }
        for (int m = 1; m < kM; m++) {
            for (int n = 1; n < kN; n++) {
                if (sum_grid[m-1][n] < sum_grid[m][n-1]) {
                    sum_grid[m][n] = sum_grid[m-1][n] + grid[m][n];
                } else {
                    sum_grid[m][n] = sum_grid[m][n-1] + grid[m][n];
                }
            }
        }
        return sum_grid[kM-1][kN-1];
    }
};
