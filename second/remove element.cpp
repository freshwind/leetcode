class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int end = n-1;
        for (int i = 0; i <= end; ++i) {
            if (A[i] == elem) {
                while(i < end && A[end] == elem) end--;
                if (end == i) {
                    return i;
                } else {
                    A[i] = A[end];
                    end--;
                }
            }
        }
        return end+1;
    }

    int removeElement2(int A[], int n, int elem) {
        int m = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] != elem) {
                A[m++] = A[i];
            }
        }
        return m;
    }
};

