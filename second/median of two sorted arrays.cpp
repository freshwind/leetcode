#include "stdlib.h"

class Solution {
public:
    int findKth(int A[], int m, int B[], int n, int k) {
        int a_begin = max(0, k-n-1);
        int a_end = min(m, k) - 1;
        int b_begin = max(0, k-m-1);
        int b_end = min(n, k) - 1;
        int a_median;
        int b_index;
        if (k<=m && (n==0 || A[k-1] <= B[0])) return A[k-1];
        if (k<=n && (m==0 || B[k-1] <= A[0])) return B[k-1];
        while (a_begin <= a_end) {
            a_median = (a_begin + a_end)/2;
            b_index = k - a_median - 2;
            if (A[a_median] == B[b_index]) {
                return A[a_median];
            } else if (A[a_median] > B[b_index]) {
                if (b_index == n-1 || A[a_median] < B[b_index+1]) {
                    return A[a_median];
                }
                a_end = a_median-1;
                b_begin = max(b_begin, b_index+1);
            } else {
                if (a_median == m-1 || A[a_median+1] > B[b_index]) {
                    return B[b_index];
                }
                b_end = min(b_end, b_index-1);
                a_begin = a_median+1;
            }
        }
        return B[b_begin];
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m+n)%2 == 0) {
            return (findKthPdf(A,m,B,n,(m+n)/2) + findKthPdf(A,m,B,n,(m+n)/2+1))/2.0;
        } else {
            return findKthPdf(A,m,B,n,(m+n+1)/2);
        }
    }
private:
    static int findKthPdf(int A[], int m, int B[], int n, int k) {
        if (m > n) return findKthPdf(B,n,A,m,k);
        if (m == 0) return B[k-1];
        if (k == 1) return min(A[0], B[0]);

        int ai = min(k/2, m);
        int bi = k-ai;
        if(A[ai-1] < B[bi-1]) {
            return findKthPdf(A+ai, m-ai, B, n, k-ai);
        } else if (A[ai-1] > B[bi-1]) {
            return findKthPdf(A, m, B+bi, n-bi, k-bi);
        } else {
            return A[ai-1];
        }
    }
};

int main() {
    Solution sol;
    int A[] = {2,3,4,5,6,7};
    int B[] = {1};
    cout <<sol.findMedianSortedArrays(A,6,B,1);
}

