class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int n = prices.size();
        if (n < 2)
            return 0;

        int profit = 0;           // Maximum profit if no stock is bought
        int bought = -prices[0]; // Maximum profit if a stock is bought

        for (int i = 1; i < n; i++) {
            profit = max(profit, bought + prices[i] );  // Sell the stock with fee
            bought = max(bought, profit - prices[i]);     // Buy the stock
        }

        return profit;
    }
  
};