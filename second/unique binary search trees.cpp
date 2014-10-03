#include "stdlib.h"

class Solution {
public:
    int numTrees(int n) {
        if (n < 2) return 1;
        vector<int> result(n+1, 0);
        result[0] = result[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int left = 0; left < i; left++) {
                result[i] += result[left] * result[i-left-1];
            }
        }
        return result[n];
    }
};

int main() {
    Solution sol;
    TreeNode *t = new TreeNode(1);
    if (t) cout <<"yes" <<endl;
    else cout <<"no" <<endl;
    // bool test = NULL;
    // print(test);
    cout <<sol.numTrees(3);
}