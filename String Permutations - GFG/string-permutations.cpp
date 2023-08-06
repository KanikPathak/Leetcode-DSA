//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    //Complete this function&
    void solve(string st, int ind, vector<string> &ans ){
        
        if(ind == st.size() ){
            ans.push_back(st);
            return ;
        }
        
    for(int i= ind; i<st.size();i++){
        
        swap(st[i],st[ind]);
        solve(st,ind+1,ans);
        swap(st[i],st[ind]);
        
    }
        
}
    
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string> ans;
        solve(S,0,ans);
       sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends