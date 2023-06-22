class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n < 2)
            return 0;

        int maxProfit = 0;           // Maximum profit if no stock is bought
        int minPrice = -prices[0]; // Maximum profit if a stock is bought

        for (int i = 1; i < n; i++) {
            maxProfit = max(maxProfit, minPrice + prices[i] - fee);  // Sell the stock with fee
            minPrice = max(minPrice, maxProfit - prices[i]);     // Buy the stock
        }

        return maxProfit;
    }
};
