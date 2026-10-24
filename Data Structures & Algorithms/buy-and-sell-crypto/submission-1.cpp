class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp = 0;
        int buy = 0;
        int sell = 1;
        int n = prices.size();

        while(sell < n) {
            mp = max(mp, prices[sell] - prices[buy]);
            if (prices[buy] <= prices[sell]) {
                sell++;
            }
            else {
                buy++;
            }
        }
        return mp;
    }
};
