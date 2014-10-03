class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int level = triangle.size()-1;
        vector<int> min = triangle[level];
        int current_level = level;
        while (current_level>0) {
            for (int i = 0; i < current_level; ++i) {
                if (min[i]>min[i+1]) {
                    min[i] = triangle[current_level-1][i] + min[i+1];
                } else {
                    min[i] += triangle[current_level-1][i];
                }
            }
            current_level--;
        }
        return min[0];
    }
};