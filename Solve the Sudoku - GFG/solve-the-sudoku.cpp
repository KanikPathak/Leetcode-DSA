//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
      bool isSafe(int board[N][N], int row, int col, int ch){

        for(int i=0; i< 9; i++){
        // check row
            if(ch == board[row][i])
                return 0;

        // check column        
            if(ch == board[i][col]) 
                return 0;
        
        // check 3*3 matrix
            if(ch == board[3* (row/3) + i/3][3*(col/3) + i%3])
                return 0;

        }
      return 1;


}
    
    bool SolveSudoku(int board[N][N])  
    { 
        // Your code here
        for(int i=0; i<N ;i++){
            for(int j=0; j<N; j++){

                    if(board[i][j] == 0){
                        for(int k=1; k<= 9; k++){
                            if(isSafe(board,i,j,k)){
                                board[i][j] = k;          
                        
                            if(SolveSudoku(board))  // agar ye number dalke board theek h to true return karo
                                return true;

                            else
                                board[i][j] = 0;
                        
                            }

                        }
            // 1-9 tak kuch nahin bhar paaya to false return kardo
                    return false;
                    }
            }
        }
return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here
         for(int i=0; i<N ;i++){
            for(int j=0; j<N; j++){
                cout<<grid[i][j]<<" ";
            }
         }    
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends