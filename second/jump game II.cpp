class Solution {
public:
    int jump(int A[], int n) {
        if (n==1) return 0;
        vector<int> dp(n, -1);
        dp[0] = 0;
        int last = 0;
        for (int i = 0; i <= last; ++i) {
            if (i+A[i] >= n-1) return dp[i]+1;
            for (last++; last <= i+A[i]; last++)
                dp[last] = dp[i]+1;
            last--;
        }
        return -1;
    }
};

class Solution {
public:
    int jump(int A[], int n) {
        int curr = 0;
        int last = curr;
        int step = 0;
        for (int i = 0; i < n; ++i) {
            if (i > curr) {
                curr = last;
                step++;
            }
            last = max(last, i+A[i]);
        }
        return step;
    }
};