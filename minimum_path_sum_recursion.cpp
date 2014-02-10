class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int kM = grid.size();
        int kN = grid[0].size();
        int m = 0;
        int n = 0;
        int sum = grid[m][n];
        min_sum = 0;
        pathSumRec(grid, kM, kN, sum, min_sum, m, n);
        return min_sum;
    }

    void pathSumRec(vector<vector<int> > &grid, int &kM, int &kN, int &sum, int &min_sum, int &m, int &n) {
        if (m==kM-1 && n==kN-1) {
            if (min_sum == 0) {
                min_sum = sum;
            }
            if (min_sum > sum) {
                min_sum = sum;
            }
            return;
        }
        if (m<kM) {
            m++;
            sum = sum + grid[m][n];
            pathSumRec(grid, kM, kN, sum, min_sum, m, n);
            sum = sum - grid[m][n];
            m--;
        }
        if (n<kN) {
            n++;
            sum = sum + grid[m][n];
            pathSumRec(grid, kM, kN, sum, min_sum, m, n);
            sum = sum - grid[m][n];
            n--;
        }
    }
};
