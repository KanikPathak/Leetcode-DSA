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
  
    void insert(TreeNode* root, vector<int> &arr){
          
        if(root==NULL)
          return ;
           insert(root->left, arr);
         arr.push_back(root->val);
        
          insert(root->right, arr);
          
          
    }
  
  
    int getMinimumDifference(TreeNode* root) {
      
      TreeNode* top= root;
      vector<int> arr;
      
      insert( top , arr );
      
      sort(arr.begin(),arr.end());
      
      int diff= arr[1]-arr[0];
      for(int i=1; i<arr.size()-1 ;i++){
        diff= min(diff,arr[i+1]-arr[i]);
        
      }
      return diff;
      
    }
};