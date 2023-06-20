class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int ans=0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(s[i]);
                ans++;
            }

            else if(s[i] == ')'){
                if(!st.empty() && st.top() == '(') {   
                    st.pop();
                    ans--;}
                else
                    ans++;
                //                 
        }        

}
  return ans;  }
};