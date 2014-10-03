class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size()<2) return 0;
        int first_buy = 1000;
        int first_sell = 1000;
        int second_buy = 1000;
        int second_sell = 1000;
        int min = 1000;
        int profit_com_fs;
        int profit_com_sc;
        int profit_del_f;
        int profit_del_s;
        int profit_del_c;
        if (prices[0] < prices[1]) {
            second_buy = prices[0];
            second_sell = prices[1];
            min = second_sell;
        } else {
            min = prices[1];
        }
        for (int i = 2; i < prices.size(); ++i) {
            if (prices[i] <= min) { // current smaller than min
                min = prices[i];
            } else {
                profit_del_c = first_sell+second_sell-first_buy-second_buy;
                profit_com_fs = second_sell - first_buy + prices[i] - min;
                profit_com_sc = first_sell- first_buy + prices[i] - second_buy;
                profit_del_f = second_sell - second_buy + prices[i] - min;
                profit_del_s = first_sell -first_buy + prices[i] - min;
                //test
                // cout <<profit_del_c <<endl;
                if (profit_com_fs > profit_del_c &&
                    profit_com_fs >= profit_com_sc &&
                    profit_com_fs >= profit_del_f &&
                    profit_com_fs >= profit_del_s) {
                    first_sell = second_sell;
                    second_buy = min;
                    second_sell = prices[i];
                    min = prices[i];
                } else if (profit_com_sc > profit_del_c &&
                           profit_com_sc >= profit_com_fs &&
                           profit_com_sc >= profit_del_s &&
                           profit_com_sc >= profit_del_f) {
                    second_sell = prices[i];
                    min = prices[i];
                } else if (profit_del_f > profit_del_c &&
                           profit_del_f >= profit_com_fs &&
                           profit_del_f >= profit_com_sc &&
                           profit_del_f >= profit_del_s) {
                    first_buy = second_buy;
                    first_sell = second_sell;
                    second_buy = min;
                    second_sell = prices[i];
                    min = prices[i];
                } else if (profit_del_s > profit_del_c &&
                           profit_del_s >= profit_com_fs &&
                           profit_del_s >= profit_com_sc &&
                           profit_del_s >= profit_del_f) {
                    second_buy = min;
                    second_sell = prices[i];
                    min = prices[i];
                }
            }
        }
        return first_sell+second_sell-first_buy-second_buy;
    }
};