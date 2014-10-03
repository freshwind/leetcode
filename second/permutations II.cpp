class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        results.clear();
        // result.resize(num.size());
        used = vector<bool>(num.size(), false);
        sort(num.begin(), num.end());
        dfs(num);
        return results;
    }
private:
    vector<vector<int> > results;
    vector<int> result;
    vector<bool> used;
    void dfs(vector<int> &num) {
        if (result.size() == num.size()) {
            results.push_back(result);
            return;
        }
        for (int i = 0; i < num.size(); ++i) {
            if (!used[i] && (i==0 || num[i] != num[i-1] || used[i-1])) {
                used[i] = true;
                result.push_back(num[i]);
                dfs(num);
                result.pop_back();
                used[i] = false;
            }
        }
    }
};
