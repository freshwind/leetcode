class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty()) return 0;
        vector<int> height(matrix[0].size()+1, 0);
        int result = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j]=='1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }
            result = max(result, largestRectangleArea(height));
        }
        return result;
    }
private:
    int largestRectangleArea(vector<int> &height) {
        if (height.size() == 0) return 0;
        vector<int> stack;
        int result = 0;
        for (int i = 0; i < height.size(); ) {
            if (stack.empty() || height[i]>height[stack.back()]) {
                stack.push_back(i++);
            } else {
                int last = stack.back();
                stack.pop_back();
                int len = stack.empty() ? i : i-stack.back()-1;
                result = max(result, len*height[last]);
            }
        }
        return result;
    }
};
