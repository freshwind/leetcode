class Solution {
public:
    bool search(int A[], int n, int target) {
        int begin = 0;
        int end = n-1;
        int middle;
        while (begin <= end) {
            middle = (begin+end)/2;
            if (A[middle] == target) {
                return true;
            }
            if (A[middle] == A[begin]) {
                begin++;
            } else if (A[middle] < target) {
                if (A[middle] > A[begin] || A[end] >= target) {
                    begin = middle+1;
                } else {
                    end = middle-1;
                }
            } else {
                if (A[middle]  < A[begin] || A[begin] <= target) {
                    end = middle-1;
                } else {
                    begin = middle+1;
                }
            }
        }
        return false;
    }
};