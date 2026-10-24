class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp = 0;
        int minBuy = prices[0];

        for(auto sell : prices) {
            mp = max(mp, sell - minBuy);
            minBuy = min(minBuy, sell);
        }
        return mp;
    }
};
