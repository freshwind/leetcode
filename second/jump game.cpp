class Solution {
public:
    bool canJump(int A[], int n) {
        int range = 0;
        int i = 0;
        while (i<=range) {
            range = max(range, i+A[i++]);
            if(range >= n-1) return true;
        }
        return false;
    }
};
