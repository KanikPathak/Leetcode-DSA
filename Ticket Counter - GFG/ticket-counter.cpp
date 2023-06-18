//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        
        deque<int>q;
        for(int i=1; i<= N;i++){
            q.push_back(i);
        }
        
        
        while(q.size()!=1){
            for(int i=0;i<K && q.size()!=1;i++){
                    q.pop_front();    
            }   
            
             for(int i=0;i<K&& q.size()!=1;i++){
                    q.pop_back();    
            } 
            
            
            
        }
    return q.front();
        
    }
};

// 


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends