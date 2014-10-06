class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if (height.size() == 0) return 0;
        vector<int> stack;
        int largest = height[0];
        int temp;
        int j;
        for (int i = 0; i < height.size(); ++i) {
            if (stack.empty() || height[stack.back()] <= height[i]) {
                stack.push_back(i);
            } else if (height[stack.back()] > height[i]) {
                while (stack.size() > 1 && height[stack.back()] > height[i]) {
                    j = stack.size()-1;
                    temp = (i - stack[j-1]-1)*height[stack[j]];
                    if (temp > largest) largest = temp;
                    stack.pop_back();
                }
                if (stack.size() == 1 && height[stack.back()] > height[i]) {
                    temp = (i - 0)*height[stack.back()];
                    if (temp > largest) largest = temp;
                    stack.pop_back();
                }
                stack.push_back(i);
            }
        }
        while (stack.size() > 1) {
            j = stack.size()-1;
            temp = (height.size() - stack[j-1]-1)*height[stack[j]];
            if (temp > largest) largest = temp;
            stack.pop_back();
        }
        if (stack.size() == 1) {
            temp = (height.size() - 0)*height[stack.back()];
            if (temp > largest) largest = temp;
            stack.pop_back();
        }
        return largest;
    }

    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() == 0) return 0;
        vector<int> height(matrix[0].size(), 0);
        int max = 0;
        int temp;
        for (int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }
            temp = largestRectangleArea(height);
            if (temp > max) max = temp;
        }
        return max;
    }
};