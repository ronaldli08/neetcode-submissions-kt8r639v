class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = 0;
        int n = prices.size();

        int sell = 1;

        while(sell < prices.size()) {
            profit = max(profit, prices[sell] - prices[buy]);
            if(prices[buy] > prices[sell]) {
                buy = sell;
            }
            ++sell;
        }
        return profit;
    }
};
