#include "stdlib.h"
class Solution {
public:
    int sqrt(int x) {
        if (x < 2) return x;
        int start = 1;
        int end = x;
        while(start <= end) {
            int middle = (start+end)/2;
            if (middle == x/middle) {
                return middle;
            } else if (middle > x/middle) {
                end = middle-1;
            } else {
                start = middle+1;
            }
        }
        return end;
    }
};

int main() {
    Solution sol;
    cout <<sol.sqrt(25);
}

//remember you should try to use minus and divide to avoid overflow