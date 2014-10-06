#include "stdlib.h"

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int m = strlen(haystack);
        int n = strlen(needle);
        if (n==0) return haystack;
        vector<int> T(n, 0);
        T[0] = -1;
        T[1] = 0;
        // abcabc
        for (int i = 2; i < n; ++i) {
            for (int j = T[i-1]; j!=-1; j = T[j]) {
                if (needle[j] == needle[i-1]) {
                    T[i] = j+1;
                    break;
                }
            }
        }
        int j = 0;
        // print(T);
        for (int i = 0; i < m; ) {
            // cout <<i <<" " <<j << endl;
            if (j == n) {
                return haystack+i-n;
            } else if (j<0 || haystack[i] == needle[j]) {
                ++i;
                ++j;
            } else {
                j = T[j];
            }
        }
        // cout <<"test"<<endl;
        if (j == n) {
            return haystack+m-n;
        } else {
            return NULL;
        }
    }
};

int main() {
    char haystack[] = "aaacaa";
    char needle[] = "aacaa";
    Solution sol;
    cout <<sol.strStr(haystack, needle);
    return 1;
}