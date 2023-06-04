// class Solution {
// public:
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         vector<vector<int>> check = isConnected;
//       int row= isConnected.size();
//       int col= isConnected[0].size();
    
      
//       for(int i=0;i<row;i++){
//         for(int j=0;j<col;j++){
//           if(isConnected[i][j]==1 && check[i][j] == 1 && i!=j){
         
//             // check i j one h to ise or j i ko 0 krdo
//             check[i][j]=0;
//             check[j][i]=0;
//             check[j][j]=0; 
//           }
            
//         }
//       }
//     int count =0;
// // return number of one in map
//     for(int i=0; i<row ; i++){
//         for(int j=0;j<col;j++){
//           if(check[i][j]== 1)
//             count++;
//         }
//       }
//   return count;
        
//         }
                         
// };
// // dusri matrix bana usme ifChanged krke func bna agar 1 aya khud ke alawa to use or uske reverse ko 0 krdo or agar kisi row mei old or new alag hai toh
// // wo 


// // (11)  (12)   13           // 1 0 0
// // (21) ( 22 )  23           //  0 0 0
// //  31   32    (33)          // 0 0 1



// // 0 0 -> 1 = 
// // 0 1 -> 1 = 
// // 0 2 -> 0 = 
// // 1 0 -> 1 = 
// // 1 1 -> 1 = 
// // 1 2 -> 0 = 
// // 2 0 -> 0 = 
// // 2 1 -> 0 = 
// // 2 2 -> 1 = 
// // jaise hi khud ke alawa 1 encounter ho toh j wale ko group krdo uske sath 
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = n;  // Initialize count with the number of vertices

        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;  // Initialize each vertex as its own parent
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1 && find(parent, i) != find(parent, j)) {
                    // If vertices i and j are connected and belong to different groups
                    // Merge the groups by updating the parent of j's group
                    parent[find(parent, j)] = find(parent, i);
                    count--;
                }
            }
        }

        return count;
    }

    int find(vector<int>& parent, int i) {
        // Find the parent (group representative) of vertex i
        if (parent[i] != i) {
            parent[i] = find(parent, parent[i]);  // Path compression for optimization
        }
        return parent[i];
    }
};
