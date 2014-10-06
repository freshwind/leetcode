#include "stdlib.h"
// class Solution {
// public:
//     int numDistinct(string S, string T) {
//         int result = 0;
//         dfs(S, T, 0, 0, result);
//         return result;
//     }
// private:
//     void dfs(string &S, string &T, int si, int ti, int &result) {
//         if (ti == T.size()) {
//             result++;
//             return;
//         }
//         for (int i = si; i < S.size(); ++i) {
//             if (S[i] == T[ti]) {
//                 dfs(S, T, i+1, ti+1, result);
//             }
//         }
//     }
// };

// 1234
// 0136
// 0014

class Solution {
public:
    int numDistinct(string S, string T) {
        vector<vector<int> > dp(T.size(), vector<int>(S.size(), 0));
        int sum = 0;
        for (int j = 0; j < S.size(); ++j) {
            if (S[j] == T[0]) {
                sum++;
                dp[0][j] = sum;
            } else {
                dp[0][j] = sum;
            }
        }
        for (int i = 1; i < T.size(); ++i) {
            sum = 0;
            for (int j = i; j < S.size(); ++j) {
                if (S[j] == T[i]) {
                    sum+=dp[i-1][j-1];
                    dp[i][j] = sum;
                } else {
                    dp[i][j] = sum;
                }
            }
        }
        print(dp);
        return dp[T.size()-1][S.size()-1];
    }
};

int main() {
    Solution sol;
    string S = "rabbbit";
    string T = "rabbit";
    cout <<sol.numDistinct(S, T);
}