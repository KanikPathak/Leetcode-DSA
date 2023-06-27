//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int> temp;
        
        temp.push_back(1);
        for(int i= 2; i<=N; i++){
           int size = temp.size();
            int carry=0;
            for(int j=0 ;j<size; j++){
                
                int num=  i * temp[j] +carry;      // ek array mei har ek ek krke digit store krke,
                                    //next iteration ko sabse multiply krte hue carry update krna h
                temp[j]= num%10;
                carry=num/10;
            }
            
            
            while(carry!=0){
                temp.push_back(carry%10);
                carry/=10;
            }
            
            
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends