//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	
	void solve(string st, string output, vector<string> &ans, vector<bool> visited){
	        
	        if(output.size() ==  st.size())
	            {
	                if(find(ans.begin(), ans.end(), output) == ans.end() )   
	                    {ans.push_back(output);
	                    return ;}
                    	                
	            }
	            
	       for(int i=0; i< st.size(); i++){
	           if(visited[i]==0){
	               
	               visited[i]=1;
	               output+= st[i];
	               solve(st, output, ans, visited);
	               output.pop_back();
	               visited[i]=0;
	           }
	       } 
	            
	}
	
	
		vector<string>find_permutation(string S)
		{
		    string output="";
		    vector<string> ans;
		    vector<bool> visited(S.size(),false);
		    sort(S.begin(),S.end());
		    solve(S, output, ans, visited);
		    
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends