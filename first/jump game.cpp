class Solution {
public:
    bool canJump(int A[], int n) {
        int small = n-1;
        for(int i = n-2; i != -1; --i) {
            if(A[i]+i >= small) {
                small = i;
            }
        }
        return small==0?true:false;
    }

};