class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int min = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < min) {
                min = prices[i];
            } else {
                profit = max(profit, prices[i]-min);
            }
        }
        return profit;
    }
};

