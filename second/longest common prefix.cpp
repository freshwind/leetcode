class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string common_string;
        if (strs.empty()) return common_string;
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[0][i] != strs[j][i]) {
                    return common_string;
                }
            }
            common_string.push_back(strs[0][i]);
        }
        return common_string;
    }
};
