class Solution {
public:
    void solve(vector<int>&candidates, vector<int> &temp, vector<vector<int>>& ans, int target, int ind){

        if(target == 0){

            ans.push_back(temp);
            return ;
        }

    for(int i =ind; i<candidates.size(); i++){
        if(i>ind && candidates[i] == candidates[i-1] )
            continue;    
        if(candidates[i] > target)
            break;
        temp.push_back(candidates[i]);
        solve(candidates,temp,ans,target-candidates[i],i+1);
        temp.pop_back();
    }


    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        solve(candidates,temp,ans,target,0);
    return ans;    
    }
};