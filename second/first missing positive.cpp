#include "stdlib.h"
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i = 0; i < n; ++i) {
            if (A[i] != i+1 && A[i] > 0 && A[i] <= n && A[i] != A[A[i]-1]) {
                swap(A[i], A[A[i]-1]);
                --i;
            }
        }
        // for (int i = 0; i < n; ++i) {
        //     cout <<A[i] <<" ";
        // }
        int i = 0;
        for (; i < n; ++i) {
            if (A[i] != i+1) {
                return i+1;
            }
        }
        return i+1;
    }
};

int main() {
    int A[] = {1,1};
    Solution sol;
    sol.firstMissingPositive(A, 4);
}