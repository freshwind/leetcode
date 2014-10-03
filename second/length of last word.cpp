
class Solution2 {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0;
        for (int i = 0; s[i] != '\0'; ++i) {
            if (s[i] != ' ') {
                len++;
            } else if (s[i+1] != '\0' && s[i+1] != ' ') {
                len = 0;
            }
        }
        return len;
    }
};