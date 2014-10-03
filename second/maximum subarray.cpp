class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n < 1) return 0;
        int result = A[0];
        int sum = A[0];
        for (int i = 1; i < n; i++) {
            sum = sum < 0 ? A[i] : sum+A[i];
            result = max(result, sum);
        }
        return result;
    }
private:
    int maxSubArrayRecur(int A[], int start, int end) {
        if (start == end) return A[start];
        int median = (start+end)/2;
        int result = max(maxSubArrayRecur(A, start, median),
                         maxSubArrayRecur(A, median+1, end));
        int max_left = A[median];
        int sum_left = A[median];
        for (int i = median-1; i >= start; --i) {
            sum_left += A[i];
            max_left = max(max_left, sum_left);
        }
        int max_right = A[median+1];
        int sum_left = A[median+1];
        for (int i = median+2; i <= end; ++i) {
            sum_right += A[i];
            max_right = max(max_right, sum_right);
        }
        result = max(result, max_left+max_right);
        return result;
    }
};