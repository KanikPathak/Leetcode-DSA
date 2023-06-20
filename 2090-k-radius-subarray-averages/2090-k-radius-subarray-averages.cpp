class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if (nums.size() <= 2 * k) {
            vector<int> ans(nums.size(), -1);
            return ans;
        }

        vector<int> ans;
        long long sum = 0;
        for (int i = 0; i <= 2 * k; i++) {
            if (i < k) {
                ans.push_back(-1);
            }
            sum += nums[i];
        }
        ans.push_back(sum / (2*k+1));
      int curr = k;
        int Wstart = 0;
        while (2 * k + Wstart+1 < nums.size() && curr + k < nums.size()) {
            sum -= nums[Wstart];
            sum += nums[2 * k + Wstart+1];
            ans.push_back(sum / (2*k+1));
            curr++;
            Wstart++;
        }

        while (curr < nums.size()-1) {
            ans.push_back(-1);
            curr++;
        }

        return ans;
    }
};
