#include "stdlib.h"

// class Solution {
// public:
//     bool isScramble(string s1, string s2) {
//         if (s1.size() != s2.size()) return false;
//         return isScrambleRecur(s1, s2, 0, s1.size()-1, 0, s1.size()-1);
//     }
// private:
//     bool isScrambleRecur(string &s1, string &s2, int s1_begin, int s1_end,
//                          int s2_begin, int s2_end) {
//         if (s1_end == s1_begin) {
//             return s1[s1_begin] == s2[s2_begin] ? true:false;
//         }
//         for (int i = s1_begin; i < s1_end; ++i) {
//             if (isScrambleRecur(s1, s2, s1_begin, i,
//                                 s2_end-i+s1_begin, s2_end) &&
//                 isScrambleRecur(s1, s2, i+1, s1_end,
//                                 s2_begin, s2_begin+s1_end-i-1)){
//                 return true;
//             } else if (isScrambleRecur(s1, s2, s1_begin, i,
//                                 s2_begin, s2_begin+i-s1_begin) &&
//                 isScrambleRecur(s1, s2, i+1, s1_end,
//                                 s2_end-s1_end+i+1, s2_end)) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        int n = s1.size();
        dp.assign(n, vector<vector<char> >(n, vector<char>(n+1, 2)));
        return dfs(s1, s2, 0, 0, n);
    }
private:
    vector<vector<vector<char> > > dp;
    bool dfs(string &s1, string &s2, int begin1, int begin2, int len) {
        if (dp[begin1][begin2][len] != 2) {
            return dp[begin1][begin2][len];
        }
        if (len == 1) {
            // cout <<dp[begin1][begin2][len];
            // print(s1[begin1]==s2[begin2]);
            dp[begin1][begin2][len] = s1[begin1]==s2[begin2]?1:0;
            return dp[begin1][begin2][len];
        } else {
            for (int i = 1; i < len; ++i) {
                if ((dfs(s1, s2, begin1, begin2, i) &&
                     dfs(s1, s2, begin1+i, begin2+i, len-i)) ||
                    (dfs(s1, s2, begin1, begin2+len-i, i) &&
                     dfs(s1, s2, begin1+i, begin2, len-i))) {
                    dp[begin1][begin2][len] = 1;
                    return 1;
                }
            }
            dp[begin1][begin2][len] = 0;
            return 0;
        }
    }
};


int main() {
    Solution sol;
    print(sol.isScramble("abb", "bba"));
    // print(sol.isScramble("ccabcbabcbabbbbcbb", "bbbbabccccbbbabcba"));
}