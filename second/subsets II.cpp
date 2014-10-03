class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > results;
        vector<int> result;
        if (S.empty()) return results;
        sort(S.begin(), S.end());
        vector<int> nums = {S[0]};
        vector<int> times = {1};
        for (int i = 1; i < S.size(); ++i) {
            if (S[i] == nums.back()) {
                times.back()++;
            } else {
                nums.push_back(S[i]);
                times.push_back(1);
            }
        }
        subsets(nums, times, result, results, 0);
        return results;
    }
    void subsets(vector<int> &nums, vector<int> &times, vector<int> result, vector<vector<int> > &results, int curr) {
        if (curr == nums.size()) {
            results.push_back(result);
            return;
        }
        subsets(nums, times, result, results, curr+1);
        for (int i = 0; i < times[curr]; ++i) {
            result.push_back(nums[curr]);
            subsets(nums, times, result, results, curr+1);
        }
    }
};

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > results;
        vector<int> result;
        dfs(results, result, S, 0);
        return results;
    }

    void dfs(vector<vector<int> > &results, vector<int> &result, vector<int> &S, int curr) {
        results.push_back(result);
        for (int i = curr; i < S.size(); ++i) {
            if (i == curr || S[i] != S[i-1]) {
                result.push_back(S[i]);
                dfs(results, result, S, i+1);
                result.pop_back();
            }
        }
    }
};

