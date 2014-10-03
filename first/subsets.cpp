class Solution {
    public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > results;
        vector<int> result;
        results.push_back(vector<int>{});
        int r_size = 0;
        sort(S.begin(), S.end());
        for (int &i:S) {
            r_size = results.size();
            for (int j = 0; j != r_size; ++j) {
                result = results[j];
                result.push_back(i);
                results.push_back(result);
            }
        }
        return results;
    }
};
