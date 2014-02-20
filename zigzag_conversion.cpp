class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) {
            return s;
        }
        int round = 2*nRows-2;
        string result;
        for (int k = 0; round*k < s.size(); k++) {
            result.push_back(s[round*k]);
        }
        for (int r = 1; r < nRows-1; r++) {
            if (r < s.size()) {
                result.push_back(s[r]);
            }
            for (int k = 1; round*k-r < s.size(); k++) {
                result.push_back(s[round*k-r]);
                if (round*k+r < s.size()) {
                    result.push_back(s[round*k+r]);
                }
            }
        }
        for (int k = 0; round*k+nRows-1 < s.size(); k++) {
            result.push_back(s[round*k+nRows-1]);
        }
        return result;
    }
};
