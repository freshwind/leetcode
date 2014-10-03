#include <vector>
#include <unordered_map>
#include "stdlib.h"

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> hash;
        unordered_map<int, int>::const_iterator got;
        vector<int> result;
        for (int i = 0; i < numbers.size(); ++i) {
            hash[numbers[i]] = i;
        }
        for (int i = 0; i < numbers.size(); ++i) {
            got = hash.find(target - numbers[i]);
            if (got != hash.end() && i != got->second) {
                // cout <<"test";
                // result.push_back(i);
                return {i, got->second};
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> numbers = {3, 2, 4};
    print(sol.twoSum(numbers, 6));
}