#include "stdlib.h"

class Solution {
    // (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
public:
    int search(int A[], int n, int target) {
        int begin = 0;
        int end = n-1;
        int middle;
        while (begin <= end) {
            middle = (begin+end)/2;
            if (A[middle] == target) {
                return middle;
            }
            if (A[middle] > target) {
                if (A[begin] > A[middle] || A[begin] <= target) {
                    end = middle-1;
                } else {
                    begin = middle+1;
                }
            } else {
                if (A[end] < A[middle] || A[end] >= target) {
                    begin = middle+1;
                } else {
                    end = middle-1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    int A[] = {0};
    cout <<sol.search(A, 1, 0);
}