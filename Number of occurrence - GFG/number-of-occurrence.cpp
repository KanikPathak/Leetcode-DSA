//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int s=0,e=n-1,ans=0;
	    
	    while(s<=e){
	        int mid = s+(e-s)/2;
	        
	        if(arr[mid] == x){
	            
	            int store = mid;
	            while(mid<n && arr[mid] == x){
	                ans++;
	                mid++;
	            }
	            while(store>=0 && arr[--store] == x)
	                ans++;
	                
        break;	                
	        }
	        
	        else if(arr[mid] < x)
	            s=mid+1;
	            
	        else
	            e=mid-1;
	    }
return ans;
}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends