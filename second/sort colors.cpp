class Solution {
public:
    void sortColor(int A[], int n) {
        int zero = 0;
        int two = n-1;
        for (int i = 0; i < two;) {
            if (A[i] == 0) {
                swap(A[zero++], A[i++]);
            } else if (A[i] == 1) {
                ++i;
            } else {
                swap(A[two--], A[i]);
            }
        }
    }

    void sortColors2(int A[], int n) {
        int zero_end = 0;
        int one_end = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] == 0) {
                A[i] = 2;
                A[one_end++] = 1;
                A[zero_end++] = 0;
            } else if (A[i] == 1) {
                A[i] = 2;
                A[one_end++] = 1;
            }
        }
    }

};
