class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0 || obstacleGrid[0][0]==1) {
            return 0;
        }

        int results[100][100];
        results[0][0] = 1;
        for (int row = 1; row < obstacleGrid.size(); row++) {
            results[row][0] = results[row-1][0]*(1-obstacleGrid[row][0]);
        }
        for (int col = 1; col < obstacleGrid[0].size(); col++) {
            results[0][col] = results[0][col-1]*(1-obstacleGrid[0][col]);
        }
        for (int row = 1; row < obstacleGrid.size(); row++) {
            for (int col = 1; col < obstacleGrid[0].size(); col++) {
                results[row][col] = (results[row-1][col] + results[row][col-1]) * (1-obstacleGrid[row][col]);
            }
        }
        return results[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};