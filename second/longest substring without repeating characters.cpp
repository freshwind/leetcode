class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> hitmap(300, true);
        list<char> substring;
        int longest = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (hitmap[s[i]]) {
                substring.push_back(s[i]);
                hitmap[s[i]] = false;
            } else {
                longest = max(longest, int(substring.size()));
                while(substring.front() != s[i]) {
                    hitmap[substring.front()] = true;
                    substring.pop_front();
                }
                substring.pop_front();
                substring.push_back(s[i]);
            }
        }
        longest = max(longest, int(substring.size()));
        return longest;
    }
};
