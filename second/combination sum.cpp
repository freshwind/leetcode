class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > results;
        vector<int> result;
        combinationSumRecur(candidates, 0, target, result, results);
        return results;
    }

private:
    void combinationSumRecur(const vector<int> &candidates, int current, int target, vector<int> &result, vector<vector<int> > &results) {
        if (target == 0) {
            results.push_back(result);
        } else if (current < candidates.size() && target >= candidates[current]) {
            combinationSumRecur(candidates, current+1, target, result, results);
            result.push_back(candidates[current]);
            combinationSumRecur(candidates, current, target-candidates[current], result, results);
            result.pop_back();
        }
    }
};
