class Solution {
public:
    vector<vector<string> > partition(string s) {
        partitionRecur(s, 0);
        return results;
    }
private:
    vector<vector<string> > results;
    vector<string> result;
    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void partitionRecur(string s, int start) {
        if (start == s.size()) {
            results.push_back(result);
        } else {
            for (int i = start; i < s.size(); ++i) {
                if (isPalindrome(s, start, i)) {
                    result.push_back(s.substr(start, i-start+1));
                    partitionRecur(s, i+1);
                    result.pop_back();
                }
            }
        }
    }
};


class Solution {
public:
    vector<vector<string> > partition(string s) {
        dp = vector<vector<int> >(s.size(), vector<int>());
        results.clear();
        result.clear();
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; i-j>=0 && i+j < s.size() && s[i-j] == s[i+j]; ++j) {
                dp[i-j].push_back(i+j);
            }
            for (int j = 0; i-j>=0 && i+1+j < s.size() && s[i-j] == s[i+j+1]; ++j){
                dp[i-j].push_back(i+j+1);
            }
        }
        dfs(s, 0);
        return results;
    }
    vector<vector<int> > dp;
    vector<vector<string> > results;
    vector<string> result;
    void dfs(string s, int start) {
        if (start == s.size()) {
            results.push_back(result);
            return;
        }
        for (int i = 0; i < dp[start].size(); ++i) {
            result.push_back(s.substr(start, dp[start][i]-start+1));
            dfs(s, dp[start][i]+1);
            result.pop_back();
        }
    }
};
