#include "stdlib.h"

class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0) return vector<int>();
        vector<int> result = {0, 1};
        int p = 1;
        for (int i = 1; i < n; ++i) {
            p *= 2;
            for (int j = result.size()-1; j >= 0; --j) {
                result.push_back(result[j]+p);
            }
        }
        return result;
    }

    //function
    vector<int> grayCode(int n) {
        vector<int> result;
        int m = 1 << n;
        for (int i = 0; i < m; ++i) {
            result.push_back(i ^ (i >> 1));
        }
        return result;
    }
};
int main() {
    Solution sol;
    print(sol.grayCode(2));
}