class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        while (start < end) {
            while(start < end && !isAlpha(s[start])) {
                start++;
            }
            while(start < end && !isAlpha(s[end])) {
                end--;
            }
            if (start >= end) return true;
            if (s[start] != s[end] && s[start]+'a'-'A' != s[end] &&
                s[start] != s[end]+'a'-'A') return false;
            start++;
            end--;
        }
        return true;
    }
private:
    bool isAlpha(char t) {
        if ((t <= 'z' && t >= 'a') || (t <= 'Z' && t >= 'A') ||
            (t <= '9' && t >= '0')) {
            return true;
        } else {
            return false;
        }
    }
};


bool isPalindrome(string s) {
    int start = 0;
    int end = s.size()-1;
    while (start < end) {
        if (!isalnum(s[start])) {
            start++;
        } else if (!isalnum(s[end])) {
            end--;
        } else if (toupper(s[start]) != toupper(s[end])) {
            return false;
        } else {
            start++;
            end--;
        }
    }
    return true;
}