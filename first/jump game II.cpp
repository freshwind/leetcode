class Solution {
public:
    int jump(int A[], int n) {
        if (n < 2) return 0;
        vector<int> jump_num(n, 2*n);
        jump_num[0] = 0;
        for (int i = 0; i < n; ++i) { //for each index
            if (i+A[i] >= n-1) { //if jump extend n-1
                if (jump_num[n-1] >= jump_num[i]+1) {
                    jump_num[n-1] = jump_num[i] + 1;
                }
            }
            if (jump_num[i]+2 < jump_num[n-1]) { //if jump_num[i]+1
                for (int j = i+A[i]; jump_num[i]+1<jump_num[j]; --j) {
                    jump_num[j] = jump_num[i] + 1;
                }
            }
        }
        if (jump_num[n-1] == 2*n) {
            return -1;
        } else {
            return jump_num[n-1];
        }
    }
};