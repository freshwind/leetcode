#include "stdlib.h"

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n<2) return n;
        int current = 0;
        int probe = current+1;
        while (probe != n) {
            if (A[current] != A[probe]) {
                A[++current] = A[probe];
            }
            probe++;
        }
        return current+1;
    }
};

