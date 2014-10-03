class Solution {
public:
    bool isPalindrome(int x) {
        int initial = x;
        int reverse = 0;
        while(x>0) {
            reverse = reverse*10 + x%10;
            x /= 10;
        }
        return reverse==initial;
    }
};

