#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int begin, end;
        int result = num[0]+num[1]+num[2];
        int closest = abs(result-target);
        int temp_sum;
        for (int i = 0; i < num.size()-2; ++i) {
            if (i && num[i] == num[i-1]) continue;
            begin = i+1;
            end = num.size()-1;
            while(begin < end) {
                temp_sum = num[i] + num[begin] + num[end];
                if (temp_sum == target) {
                    return target;
                } else if (temp_sum > target) {
                    end--;
                } else {
                    begin++;
                }
                if (abs(temp_sum-target) < closest) {
                    closest = abs(temp_sum-target);
                    result = temp_sum;
                }
            }
        }
        return result;
    }
};
