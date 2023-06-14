class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int count=0;
        int n= nums.size();
        long long sum=0;
        // aise split krna hai k pichhle wale ka sum zyda ho
        for(int i=0; i<n; i++){
        sum+=nums[i];
        }
        long long currSum=0;
        for(int i=0;i<n-1;i++){
          sum=sum-nums[i];
          currSum+=nums[i];
          if(currSum >= sum )
           count++;

        }
    return count;}
};

// 13