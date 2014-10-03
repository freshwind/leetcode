//first solution which is from bottom to the top is better!
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<int> dp(triangle.size(), 0);
        dp[0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); ++i) {
            dp[i] = dp[i-1]+triangle[i][i];
            for (int j = i-1; j > 0; --j) {
                dp[j] = min(dp[j], dp[j-1]) + triangle[i][j];
            }
            dp[0] = dp[0]+triangle[i][0];
        }
        return *min_element(dp.begin(), dp.end());
    }
};
