class Solution {
public:
    bool isAlphaNumeric(char &c) {
        if (c>='0' && c<='9') {
            return true;
        }
        if (c>='a' && c<='z') {
            return true;
        }
        if (c>='A' && c<='Z') {
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        if (s.size() == 0) return true;
        int start = 0;
        int end = s.size()-1;
        while (start < end) {
            if (!isAlphaNumeric(s[start])) { //start != char
                start++;
            } else if (!isAlphaNumeric(s[end])) { //end != char
                end--;
            } else if (s[start] == s[end] || (s[start]+'a'-'A') == s[end] || s[start] == (s[end]+'a'-'A')) {//match
                start++;
                end--;
            } else {
                return false;
            }
        }
        return true;
    }
};