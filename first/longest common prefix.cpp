class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string common_string;
        if (strs.size() == 0) {
            return common_string;
        }
        if (strs.size() == 1) {
            return strs[0];
        }
        for (int i = 0; i<strs[0].size() && i<strs[1].size(); i++) {
            if(strs[0][i] == strs[1][i]) {
                common_string.push_back(strs[0][i]);
            } else {
                break;
            }
        }
        for (int i = 2; i<strs.size(); i++) {
            if (common_string.size()==0) {
                return common_string;
            } else {
                int j;
                for (j = 0; j<common_string.size() && common_string[j]==strs[i][j]; ++j);
                if (j!=common_string.size()) {
                    common_string.erase(j, common_string.size()-j);
                }
            }
        }
        return common_string;
    }
};