#include "stdlib.h"

class Solution {
public:
    int singleNumber(int A[], int n) {
        int result = 0;
        for (int i = 0; i < n; i++) {
            result ^= A[i];
        }
        return result;
    }
};

int main() {
    Solution sol;
    int A[5] = {1, 1, 2, 2, 3};
    cout <<sol.singleNumber(A, 5);
}