class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > results;
        vector<int> result;
        combineRecur(results, result, n, k, 0);
        return results;
    }
    void combineRecur(vector<vector<int> > &results, vector<int> &result,
                      const int &n, const int &k, int back) {
        if (result.size() == k) {
            results.push_back(result);
            return;
        }
        for (int i = back+1; i <= n-(k-result.size())+1; ++i) {
            result.push_back(i);
            combineRecur(results, result, n, k, i);
            result.pop_back();
        }
    }
};
