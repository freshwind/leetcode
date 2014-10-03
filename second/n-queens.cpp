class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        solve(n);
        return results;
    }
private:
    vector<vector<string> > results;
    vector<string> result;
    void solve(int n) {
        if (result.size() == n) {
            results.push_back(result);
        } else {
            string line = string(n, '.');
            for (int i = 0; i < n; ++i) {
                if (check(i)) {
                    line[i] = 'Q';
                    result.push_back(line);
                    solve(n);
                    result.pop_back();
                    line[i] = '.';
                }
            }
        }
    }
    bool check(int i) {
        int left = i-1;
        int right = i+1;
        for (int j = result.size()-1; j >= 0; --j) {
            if ((left>=0 && result[j][left] == 'Q') || (right<n && result[j][right] == 'Q') || result[j][i] == 'Q') {
                return false;
            }
            left--;
            right++;
        }
        return true;
    }
};

