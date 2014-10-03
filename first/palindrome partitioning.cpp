class Solution {
public:
    bool isPalindrome(const string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void partitionRecur(const string &s, int start, int end,
                        vector<string> &result,
                        vector<vector<string> > &results) {
        if (start > end) {
            results.push_back(result);
        } else {
            for (int i = start; i <= end; ++i) {
                if (isPalindrome(s, start, i)) {
                    result.push_back(s.substr(start, i-start+1));
                    partitionRecur(s, i+1, end, result, results);
                    result.pop_back();
                }
            }
        }
    }

    vector<vector<string> > partition(string s) {
        vector<vector<string> > results;
        vector<string> result;
        partitionRecur(s, 0, s.size()-1, result, results);
        return results;
    }
};