#include "stdlib.h"
// class Solution {
// public:
//     int maxProfit(vector<int> &prices) {
//         if (prices.size()<2) return 0;
//         int first_buy = prices[0];
//         int first_sell = prices[0];
//         int second_buy = prices[0];
//         int second_sell = prices[0];
//         int min = prices[0];
//         int profit_com_fs;
//         int profit_com_sc;
//         int profit_del_f;
//         int profit_del_s;
//         int profit_del_c;
//         for (int i = 1; i < prices.size(); ++i) {
//             if (prices[i] <= min) { // current smaller than min
//                 min = prices[i];
//             } else {
//                 profit_del_c = first_sell+second_sell-first_buy-second_buy;
//                 profit_com_fs = second_sell - first_buy + prices[i] - min;
//                 profit_com_sc = first_sell- first_buy + prices[i] - second_buy;
//                 profit_del_f = second_sell - second_buy + prices[i] - min;
//                 profit_del_s = first_sell -first_buy + prices[i] - min;
//                 //test
//                 // cout <<profit_del_c <<endl;
//                 if (profit_com_fs >= profit_del_c &&
//                     profit_com_fs >= profit_com_sc &&
//                     profit_com_fs >= profit_del_f &&
//                     profit_com_fs >= profit_del_s) {
//                     first_sell = second_sell;
//                     second_buy = min;
//                     second_sell = prices[i];
//                     min = prices[i];
//                 } else if (profit_com_sc >= profit_del_c &&
//                            profit_com_sc >= profit_com_fs &&
//                            profit_com_sc >= profit_del_s &&
//                            profit_com_sc >= profit_del_f) {
//                     second_sell = prices[i];
//                     min = prices[i];
//                 } else if (profit_del_f >= profit_del_c &&
//                            profit_del_f >= profit_com_fs &&
//                            profit_del_f >= profit_com_sc &&
//                            profit_del_f >= profit_del_s) {
//                     first_buy = second_buy;
//                     first_sell = second_sell;
//                     second_buy = min;
//                     second_sell = prices[i];
//                     min = prices[i];
//                 } else if (profit_del_s >= profit_del_c &&
//                            profit_del_s >= profit_com_fs &&
//                            profit_del_s >= profit_com_sc &&
//                            profit_del_s >= profit_del_f) {
//                     second_buy = min;
//                     second_sell = prices[i];
//                     min = prices[i];
//                 }
//             }
//         }
//         return first_sell+second_sell-first_buy-second_buy;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size()<2) return 0;
        vector<int> profit(prices.size(), 0);
        int best = 0;
        int low = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            best = max(best, prices[i]-low);
            low = min(low, prices[i]);
            profit[i] = best;
        }
        int high = prices.back();
        for (int i = prices.size()-1; i >0; --i) {
            best = max(best, profit[i-1]+high-prices[i]);
            high = max(high, prices[i]);
        }
        return best;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {1,2};
    cout <<sol.maxProfit(prices);
}