#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> hash(num.begin(),num.end());
        int center;
        int small;
        int big;
        int longest=1;
        while(!hash.empty()) {
            center = *hash.begin();
            hash.erase(center);
            small = center-1;
            while(!hash.empty() && hash.find(small) != hash.end()) {
                hash.erase(small--);
            }
            big = center+1;
            while(!hash.empty() && hash.find(big) != hash.end()) {
                hash.erase(big++);
            }
            if (big-small-1 > longest) {
                longest = big - small -1;
            }
        }
        return longest;
    }
};

int main() {
    vector<int> num = {0};
    Solution sol;
    cout <<sol.longestConsecutive(num);
    return 1;
}