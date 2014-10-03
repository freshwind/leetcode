class Solution {
public:
    bool isScrambleRecur(string &s1, string &s2, int s1_start, int s1_end,
                         int s2_start, int s2_end) {
        //if size == 1
        if (s1_start == s1_end) {
            if (s1[s1_start] == s2[s2_start]) {
                return true;
            } else {
                return false;
            }
        }

        //if same
        int i = s1_start;
        int j = s2_start;
        for (; i <= s1_end && s1[i] == s2[j]; ++i, ++j) {
        }
        if (i == s1_end+1) return true;

        //if not same chars
        unordered_map<char, int> hash_map;
        unordered_map<char, int>::iterator got;
        //create hash map by s1
        for (i = s1_start; i <= s1_end; ++i) {
            got = hash_map.find(s1[i]);
            if (got == hash_map.end()) {//if not found
                //add new
                hash_map.insert({s1[i],1});
            } else {
                got->second++;
            }
        }

        //check set of chars in s1 is same as s2
        for (j = s2_start; j <= s2_end; ++j) {
            got = hash_map.find(s2[j]);
            if (got == hash_map.end()) {
                return false;
            } else if (got->second == 1) {
                hash_map.erase(got);
            } else {
                got->second--;
            }
        }

        //now the condition is s1 has same char as s2, but not in same order
        for (i = 0; s1_start+i+1 <= s1_end; ++i) {
            if (isScrambleRecur(s1, s2, s1_start, s1_start+i,
                                s2_start, s2_start+i) &&
                isScrambleRecur(s1, s2, s1_start+i+1, s1_end,
                                s2_start+i+1, s2_end)) {
                return true;
            }
            if (isScrambleRecur(s1, s2, s1_start, s1_start+i,
                                s2_end-i, s2_end) &&
                isScrambleRecur(s1, s2, s1_start+i+1, s1_end,
                                s2_start, s2_end-i-1)) {
                return true;
            }
        }
        return false;
    }

    bool isScramble(string s1, string s2) {
        return isScrambleRecur(s1, s2, 0, s1.size()-1, 0, s2.size()-1);
    }
};