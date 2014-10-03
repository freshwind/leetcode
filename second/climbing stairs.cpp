class Solution {
public:
    int climbStairs(int n) {
        if (n<2) return 1;
        int current = 1;
        int before = 1;
        int temp;
        for (int i = 1; i < n; ++i) {
            temp = current;
            current = current + before;
            before = temp;
        }
        return current;
    }
};
