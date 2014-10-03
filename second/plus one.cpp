#include "stdlib.h"

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int remain = 1;
        int temp;
        vector<int> results(digits.begin(), digits.end());
        for (int i = digits.size()-1; i >=0; --i) {
            results[i] = remain + digits[i];
            remain = results[i]/10;
            results[i] %= 10;
            // cout <<results[i] <<"," <<remain <<"," <<i <<endl;
            if (remain == 0) break;
        }
        if (remain == 1) {
            results.insert(results.begin(), 1);
        }
        return results;
    }

    vector<int> plusOne2(vector<int> &digits) {
        bool carry = true;
        for (int i = digits.size()-1; carry && i >= 0; --i) {
            digits[i]++;
            carry = digits > 9;
            digits[i] %= 10;
        }
        if (carry) {
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }
};

int main() {
    Solution sol;
    vector<int> digits = {0};
    print(sol.plusOne(digits));
    // cout <<digits.size();
    // print(sol.plusOne(digits));
}