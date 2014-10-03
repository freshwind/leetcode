class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int reverse = 0;
        int initial = x;
        while (x>0) {
            reverse = 10*reverse + x%10;
            x /= 10;
        }
        return (initial==reverse? true : false);
    }
};