#include "stdlib.h"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0);
        vector<string> ret;
        // print(results);
        string temp = s;
        for (int i = 0; i < results.size(); ++i) {
            temp = s;
            for (int j = 2; j >= 0; --j) {
                temp.insert(temp.begin()+results[i][j], '.');
            }
            ret.push_back(temp);
        }
        return ret;
    }
private:
    vector<vector<int> > results;
    vector<int> result;
    void dfs(string s, int curr) {
        int remain = 4-result.size();
        if (curr == s.size() && !remain) {
            results.push_back(result);
            return;
        }
        if (s.size()-curr < remain || s.size()-curr > remain*3) {
            return;
        }
        if (s[curr] == '0') {
            result.push_back(curr+1);
            dfs(s, curr+1);
            result.pop_back();
            return;
        }
        for (int i = 1; i <=3 && curr+i <= s.size(); ++i) {
            int tmp = stoi(s.substr(curr, i));
            if (tmp <= 255) {
                result.push_back(curr+i);
                dfs(s, curr+i);
                result.pop_back();
            }
        }
    }
};

int main() {
    Solution sol;
    sol.restoreIpAddresses("0000");
}