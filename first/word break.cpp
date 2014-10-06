class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.size() == 0) return false;
        vector<bool> results(s.size()+1, false);
        results[0] = true;
        unordered_set<string>::const_iterator got;
        for (int i = 1; i < results.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (results[j]) {
                    got = dict.find(s.substr(j,i-j));
                    if (got != dict.end()) {
                        results[i] = true;
                        break;
                    }
                }
            }
        }
        return results.back();
    }
};