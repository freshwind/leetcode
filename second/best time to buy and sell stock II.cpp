#include "stdlib.h"

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i-1]) {
                result = result + prices[i] - prices[i-1];
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> prices;
    int i = 0;
    print(i<prices.size()-1);
    cout <<prices.size()-1 <<endl;
    cout <<prices.size() <<endl;
    cout <<sol.maxProfit(prices);
    return 1;
}
