#include "stdlib.h"

class Solution {
public:
    int maxArea(vector<int> &height) {
        int left = 0;
        int right = height.size()-1;
        int max_area = 0;
        while (left < right) {
            int curr = (right-left) * min(height[left], height[right]);
            max_area = max(max_area, curr);
            if (height[left] < height[right]) {
                int i = left+1;
                for (; left < right && height[i] <= height[left]; ++i);
                left = i;
            } else {
                int i = right-1;
                for (; left < right && height[i] <= height[right]; --i);
                right = i;
            }
        }
        return max_area;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {1,1};
    cout <<sol.maxArea(heights);
}