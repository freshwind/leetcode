class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > results;
        vector<int> result;
        combinationSumRecur(candidates, 0, target, result, results);
        return results;
    }

    void combinationSumRecur(vector<int> &candidates, int current, int target, vector<int> &result, vector<vector<int> > &results) {
        if (target == 0) {
            results.push_back(result);
            return;
        }
        if (target < candidates[current]) {
            return;
        }
        int probe = current;
        for (; probe < candidates.size() && target >= candidates[probe]; ++probe) {
            result.push_back(candidates[probe]);
            combinationSumRecur(candidates, probe, target-candidates[probe], result, results);
            result.pop_back();
        }
    }
};