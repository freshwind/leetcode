class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > result(n, vector<int>(n, 0));
        int start = 0;
        int end = n-1;
        int current = 1;
        while (start <= end) {
            for (int i = start; i <= end; ++i) {
                result[start][i] = current++;
            }
            for (int i = start+1; i <= end; ++i) {
                result[i][end] = current++;
            }
            for (int i = end-1; i >=start; --i) {
                result[end][i] = current++;
            }
            for (int i = end-1; i >start; --i) {
                result[i][start] = current++;
            }
            start++;
            end--;
        }
        return result;
    }
};
