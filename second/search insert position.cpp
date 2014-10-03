#include "stdlib.h"

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (target > A[n-1]) return n;
        if (target <= A[0]) return 0;
        if (target == A[n-1]) return n-1;
        int smaller = 0;
        int bigger = n-1;
        int median;
        while (smaller+1 != bigger) {
            median = (smaller+bigger)/2;
            if (target == A[median]) return median;
            else if (target > A[median]) {
                smaller = median;
            } else {
                bigger = median;
            }
        }
        return bigger;
    }
};

//easy version
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int begin = 0;
        int end = n-1;
        while (begin <= end) {
            int median = (begin+end)/2;
            if (target == A[median]) return median;
            else if (target < A[median]) end = median-1;
            else begin = median+1;
        }
        return begin;
    }
};
