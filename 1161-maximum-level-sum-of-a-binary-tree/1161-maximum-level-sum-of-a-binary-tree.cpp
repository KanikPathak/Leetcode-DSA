/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  
  void levelSums(TreeNode* root,int level, unordered_map<int,int> &mp){
    
    if(root == NULL)
      return ;
    
    mp[level] += root->val;
    
    levelSums(root->left, level+1, mp);
    levelSums(root->right, level+1, mp);
    
  }
  
  
    int maxLevelSum(TreeNode* root) {

      // Har level ka sum ek map mei sotre kro or fir max ke corresponding return krdo
      
      
      unordered_map<int,int> mp;
      
      levelSums(root,1,mp);
      
      int maxSum= INT_MIN;
      
      int ans= 0;
      for(int i=1 ;i<=mp.size();i++){
        
          if(mp[i] > maxSum )
          {
            maxSum= mp[i];
            ans=i;
          }
      }
        
  return ans;   
    }
};