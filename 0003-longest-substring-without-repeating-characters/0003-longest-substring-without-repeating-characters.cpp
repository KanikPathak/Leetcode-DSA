class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     
      // unordered set to be used to keep track of repeating characters
      
      int i=0,j=0;
      int ans=0;
      int n=s.length();
      unordered_set<char> st;
      
      while(i<n && j<n){
        // i window ki starting
        // j window ka end
        
        
        if(st.count(s[j])==0 )             // agar element present nhi hai set mei to daldo
        {
          st.insert(s[j++]);
          ans = max(ans, j-i);
        }
        else
        {
          st.erase(s[i++]);                // i ko erase kardo qki window mei ek repetition aa gya hai
        }                                   // jb tk repetition wala char hat ma jaye tb tk aage bdhte rahega i   
        
      }
      
    return ans;
    }
};