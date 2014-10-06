class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int result = 0;
        while (1) {
            int j = 0;
            int i = result;
            for (; needle[j] != '\0'; ++i, ++j) {
                if (haystack[i] == '\0' || haystack[i] != needle[j]) {
                    break;
                }
            }
            if (needle[j] == '\0') {
                return haystack+result;
            }
            if (haystack[i] == '\0') {
                return NULL;
            }
            result++;
        }
    }
};