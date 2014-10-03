#include <vector>
#include "stdlib.h"
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > results;
        sort(num.begin(), num.end());
        for (int i = 0; i < int(num.size())-2; ++i) {
            if (i && num[i] == num[i-1]) continue;
            int begin = i+1;
            int end = num.size()-1;
            while (begin < end) {
                if (num[begin]+num[end] == -num[i]) {
                    results.push_back({num[i], num[begin], num[end]});
                    begin++;
                    end--;
                    while(begin < end && num[begin] == num[begin-1]) {
                        begin++;
                    }
                    while(begin <end && num[end] == num[end+1]) {
                        end--;
                    }
                } else if (num[begin]+num[end] < -num[i]) {
                    begin++;
                } else {
                    end--;
                }
            }
        }
        return results;
    }
};

int main() {
    Solution sol;
    vector<int> num = {};
    print(sol.threeSum(num));
}