//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int matchGame(long long N) {
        // code here
        // last matchstick uski rahe aisa krna hai so every time use 
        
        // if(N % 4 == 1)
        //   return -1; 
        
        // if(N==4)
        //     return 4;
            
        // if(N % 4 == 0)
        //     return 3;
        
        // if(N % 4 ==2)
        //     return 1;
            
        // if( N % 4 ==3)
        //     return 2;
       
       
       //1 2 3 4 are remainders of 5
       
       int temp= N%5;
       if(temp == 0 )
        return -1;
        
        return temp;    
        
       
            
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.matchGame(N) << endl;
    }
    return 0;
}
// } Driver Code Ends