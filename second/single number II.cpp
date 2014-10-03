#include <iostream>
using namespace std;
class Solution {
public:
    int singleNumber(int A[], int n) {
        int result = 0;
        int sup = 0;
        int temp;
        for (int i = 0; i < n; ++i) {
            sup ^= result & A[i];
            result ^= A[i];
            temp = result & sup;
            result ^= temp;
            sup ^= temp;
        }
        return result;
    }
};

int main() {
    int A[] = {1,1,1,2};
    Solution sol;
    cout <<sol.singleNumber(A, 4);
}