#include "stdlib.h"

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x!=0) {
            result = result*10 + x%10;
            x /= 10;
        }
        return result;
    }
};

int main() {
    Solution sol;
    cout <<sol.reverse(-123);
}