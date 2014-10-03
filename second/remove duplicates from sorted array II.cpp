#include "stdlib.h"

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 3) return n;
        int current = 1;
        for (int probe = 2; probe < n; probe++) {
            if (A[probe] != A[current] || A[probe] != A[current-1]) {
                A[++current] = A[probe];
            }
        }
        return current+1;
    }
};

int main() {
    int A[] = {1,1, 2};
    Solution sol;
    cout <<sol.removeDuplicates(A, 3);
}