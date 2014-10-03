class Solution {
    public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<int> result;
        vector<vector<int> > results;
        results.push_back(vector<int>{});
        int rs;
        for (int i = 0; i < S.size(); ++i) {
            rs = results.size();
            for (int j = 0; j < rs; ++j) {
                result = results[j];
                result.push_back(S[i]);
                results.push_back(result);
            }
        }
        return results;
    }
};
