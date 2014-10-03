class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (strlen(s) == 0) {
            return 0;
        }
        int i = strlen(s);
        while (i>0 && s[--i] == ' ');
        int start = i;
        if (s[start] == ' ') {
            return 0;
        }
        while (i>0) {
            if (s[--i] == ' ') {
                return (start-i);
            }
        }
        return start+1;
    }
};

