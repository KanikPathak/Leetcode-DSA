class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int row= grid.size();
        int col= grid[0].size();
      
      vector<vector<int>> tp= grid;
      int count=0;
      
      for(int i=0;i<row;i++){
        for(int j=0 ;j<col;j++){
          tp[j][i] = grid[i][j];
        }
        
      }
      
      for(int i=0; i< row; i++){
        for(int j=0; j<row; j++){
          int k;
          for(k=0;k<col;k++){
            if(grid[i][k] != tp[j][k] )
              break;
          }
          if(k == col)
            count++;
          
        }
      }
      
      
      
      
      
// //    3 2 1         3 1 2
//       1 7 6         2 7 7 
//       2 7 7         1 6 7
      
 return count;   }
};