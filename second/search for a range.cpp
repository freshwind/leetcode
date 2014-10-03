class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int begin = 0;
        int end = n-1;
        int middle;
        while(begin <= end) {
            middle = (begin+end)/2;
            if (A[middle] == target) {
                begin = searchLeft(A, 0, middle-1, target);
                end = searchRight(A, middle+1, n-1, target);
                return {begin, end};
            } else if (A[middle] < target) {
                begin = middle+1;
            } else {
                end = middle-1;
            }
        }
        return {-1, -1};
    }

    int searchLeft(int A[], int begin, int end, const int &target) {
        int left;
        while (begin <= end) {
            left = (begin+end)/2;
            if (A[left] == target) {
                end = left-1;
            } else {
                begin = left+1;
            }
        }
        return begin;
    }

    int searchRight(int A[], int begin, int end, const int &target) {
        int right;
        while (begin <= end) {
            right = (begin+end)/2;
            if (A[right] == target) {
                begin = right+1;
            } else {
                end = right-1;
            }
        }
        return end;
    }
};