class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        string output = "";

        for (int i = 0; i < nums.size(); i++) {
            if (i + 1 < nums.size() && nums[i] == nums[i + 1] - 1) {
                if (output.empty()) {
                    output = to_string(nums[i]);
                }
            } else {
                if (!output.empty()) {
                    output += "->" + to_string(nums[i]);
                } else {
                    output = to_string(nums[i]);
                }
                ans.push_back(output);
                output = "";
            }
        }

        return ans;
    }
};
