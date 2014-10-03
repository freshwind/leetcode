class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        dfs(num, target, 0);
        return results;
    }
private:
    vector<vector<int> > results;
    vector<int> result;
    void dfs(vector<int> &num, int target,int start) {
        if (target == 0) {
            results.push_back(result);
            return;
        }
        for (int i = start; i < num.size(); ++i) {
            if (num[i] > target) break;
            if (i==start || num[i]!=num[i-1]) {
                result.push_back(num[i]);
                dfs(num, target-num[i], i+1);
                result.pop_back();
            }
        }
    }
};
