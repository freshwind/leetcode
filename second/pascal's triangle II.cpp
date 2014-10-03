class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1, 1);
        for (int row = 2; row <= rowIndex; ++row) {
            for (int i = row-1; i >= 1; --i) {
                result[i] += result[i-1];
            }
        }
        return result;
    }
};
