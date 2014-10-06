class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        unordered_set<string>::const_iterator got;
        vector<int> true_set = {0};
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < true_set.size(); ++j) {
                got = dict.find(s.substr(true_set[j], i-true_set[j]));
                if (got != dict.end()) {
                    true_set.push_back(i);
                    break;
                }
            }
        }
        return true_set.back()==s.size()?true:false;
    }
};
