class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        while (n>0) {
            if (m>0 && A[m-1] > B[n-1]) {
                A[m+n-1] = A[m-1];
                m--;
            } else {
                A[m+n-1] = B[n-1];
                n--;
            }
        }
    }

    void merge2(int A[], int m, int B[], int n) {
        int C[m+n];
        int c = 0;
        int a = 0;
        int b = 0;
        while (a<m && b<n) {
            if(A[a] < B[b]) {
                C[c++] = A[a++];
            } else {
                C[c++] = B[b++];
            }
        }
        while (a != m) {
            C[c++] = A[a++];
        }
        while (b != n) {
            C[c++] = B[b++];
        }
        for (int i = 0; i < m+n; ++i) {
            A[i] = C[i];
        }
    }
};