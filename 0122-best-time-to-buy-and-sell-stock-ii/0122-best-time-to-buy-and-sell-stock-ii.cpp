// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         // find max profit holding it and max profit not holding it
      
//       int hold= -prices[0];
//       int profit= 0;
//       cout<<profit<<" ";
//       cout<<hold<<endl;
      
//       for(int i=1; i<prices.size(); i++){
//         profit = max(profit, prices[i]+hold);   // ya bech de
       
//         hold= max(hold, profit-prices[i]);     // YA MAT BECH 
// // hold is the previous cumulation of buy price
//       }
      
//       return profit;
//     }
//};


class Solution {
public:
  int solve(vector<int> &prices, int buy, int ind, vector<vector<int>>&dp){
    
    
    
    if(ind==prices.size())
       return 0;
    
    
    if(dp[ind][buy]!= -1)
      return dp[ind][buy];
    
    
    int profit=0;
    if(buy){
    profit= max( (-prices[ind] + solve(prices,0,ind+1,dp))  ,  solve(prices,1,ind+1,dp));  
    }
    else{
      profit= max((prices[ind] + solve(prices,1,ind+1,dp)), solve(prices,0,ind+1,dp));
    }
    
    return dp[ind][buy] = profit;
    
  }
  
  
    int maxProfit(vector<int>& prices) {
       if (prices.size() < 2)
            return 0;
      
      // using DP
      vector<vector<int>>dp (prices.size(), vector<int>(2,-1));// buy and profit is changing so 2 col matrix
    return  solve(prices,1,0,dp);
     
      
      
    }
};