#include "stdlib.h"

class Solution {
public:
    int totalNQueens(int n) {
        int result = 0;
        totalNQueensRecur(n, 0, 0, 0, 0, result);
        return result;
    }

    void totalNQueensRecur(const int & n, int left, int right,
                           int middle, int level, int &result) {
        if (level == n) {
            result++;
        } else {
            int current = 1;
            int check = middle|left|right;
            for (int i = 0; i < n; ++i) {
                current = current << 1;
                if (!(check&current)) {
                    totalNQueensRecur(n, (current|left)<<1, (current|right)>>1,
                                      current|middle, level+1, result);
                }
            }
        }
    }
};

int main() {
    Solution sol;
    // cout << (1>>2);
    cout <<sol.totalNQueens(7);
}