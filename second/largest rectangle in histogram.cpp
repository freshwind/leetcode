class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if (height.empty()) return 0;
        vector<vector<int> > stack = {{0, height[0]}};
        int largest = 0;
        int index;
        for (int i = 1; i < height.size(); ++i) {
            if (height[i] > stack.back()[1]) {
                stack.push_back({i, height[i]});
            } else {
                while(stack.empty() || stack.back()[1]>=height[i]) {
                    index = stack.back()[0];
                    largest = max(largest, (i-index)*stack.back()[1]);
                    stack.pop_back();
                }
                stack.push_back({index, height[i]});
            }
        }
        int n = height.size();
        while (!stack.empty()) {
            largest = max(largest, (n-stack.back()[0])*stack.back()[1]);
        }
        return largest;
    }
};


class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // if (height.empty()) return 0;
        height.push_back(0);
        vector<int> stack;
        int largest = 0;
        int index;
        for (int i = 0; i < height.size();) {
            if (stack.empty() || height[i] > height[stack.back()]) {
                stack.push_back(i++);
            } else {
                // while(!stack.empty() && stack.back()[1]>=height[i]) {
                //     index = stack.back()[0];
                //     largest = max(largest, (i-index)*stack.back()[1]);
                //     stack.pop_back();
                // }
                int last = stack.back();
                stack.pop_back();
                int length = stack.empty() ? i : i-stack.back()-1;
                largest = max(largest, length*height[last]);
            }
        }
        // int n = height.size();
        // while (!stack.empty()) {
        //     largest = max(largest, (n-stack.back()[0])*stack.back()[1]);
        //     stack.pop_back();
        // }
        return largest;
    }
};
