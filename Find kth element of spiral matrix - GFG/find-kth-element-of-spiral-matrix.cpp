//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int startRow=0,endRow=n-1,startCol=0,endCol=m-1;
 		int count= n*m,temp=1;
 		
 		
 		while(temp<=count){
 		    
 		    for(int i=startCol; i<=endCol && temp<=count; i++){
 		        
 		        if(temp==k)
 		            return a[startRow][i];
 		        temp++;
 		    }
 		startRow+=1;
 		
 		    
 		    for(int i=startRow; i<=endRow && temp<=count; i++){
 		        if(temp == k)
 		            return a[i][endCol];
 	            temp++;
 		    }
 		    
 		    endCol-=1;
 		    
 		    for(int i= endCol; i>=startCol && temp<=count; i-- ){
 		        if( temp ==k )
 		            return a[endRow][i];
 		        temp++;
 		    }
 		    
 		    endRow-=1;
 		    
 		    
 		     
 		    for(int i=endRow ; i>=startRow && temp<=count; i-- ){
 		        if( temp ==k )
 		            return a[i][startCol];
 		        temp++;
 		    }
 		    startCol+=1;

 		}
      return -1;  
        
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends