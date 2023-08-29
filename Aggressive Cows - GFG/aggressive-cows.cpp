//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    
    bool isPossible(vector<int> &stalls,int mid, int cows){
        
        int currCow =1, currStall=stalls[0];
        
        for(int i=1; i< stalls.size(); i++){
            
            if(stalls[i] - currStall >= mid){ // if it is inside the limit then place the cow
                currStall = stalls[i];
                currCow+=1;
                if(currCow == cows)
                    return 1;
            }
            
        }
        return 0;
        
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        
        sort(stalls.begin(),stalls.end());
        int s=0, e= stalls[n-1]- stalls[0],ans=-1;
        
        
        while(s<=e){
            
            int mid = s+(e-s)/2;
            
            if(isPossible(stalls,mid,k)){
                s=mid+1;
                ans = mid;
            }
            else
                e=mid-1;
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends