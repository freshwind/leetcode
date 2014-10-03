class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > results;
        if (numRows<1) return results;
        results.push_back({1});
        vector<int> result;
        vector<int> last = {1};
        for (int i = 1; i < numRows; ++i) {
            result.push_back(1);
            for(int j = 0; j < last.size()-1; ++j) {
                result.push_back(last[j]+last[j+1]);
            }
            result.push_back(1);
            results.push_back(result);
            last = result;
            result.clear();
        }
        return results;
    }
};

class Solution2 {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > results(numRows, vector<int>());
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i) {
                    results[i].push_back(1);
                } else {
                    results[i].push_back(results[i-1][j-1]+results[i-1][j]);
                }
            }
        }
        return results;
    }
};
