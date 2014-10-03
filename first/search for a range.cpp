class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        if (n==0) {
            return vector<int>{-1,-1};
        }
        int middle;
        int start = 0;
        int end = n-1;
        while (start <= end) {
            middle = (start + end)/2;
            if (A[middle]==target) {
                start = find_left(A, n, target, start, middle);
                end = find_right(A, n, target, middle, end);
                return vector<int>{start, end};
            } else if(A[middle]<target) {
                start = middle+1;
            } else {
                end = middle-1;
            }
        }
        return vector<int>{-1,-1};
    }

    int find_left(int A[], int n, int target, int left, int right) {
        int middle = 0;
        while (left != right) {
            middle = (left+right)/2;
            if (A[middle]==target) {
                right = middle;
            } else {
                left = middle+1;
            }
        }
        return left;
    }

    int find_right(int A[], int n, int target, int left, int right) {
        int middle = 0;
        while (left != right) {
            middle = (left+right+1)/2;
            if (A[middle] == target) {
                left = middle;
            } else {
                right = middle-1;
            }
        }
        return right;
    }
};