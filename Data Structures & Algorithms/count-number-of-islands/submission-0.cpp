class Solution {
public:


  vector<int>rows = {-1,1,0,0};
  vector<int>cols = {0,0,-1, 1};
  void dfs(vector<vector<char>>&grid , int i , int j  , int n , int m){
         

         grid[i][j] = 0;

         for( int k = 0 ; k < 4 ; k++){

            int nrow = i + rows[k];
            int ncol = j + cols[k];

            if( nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
            grid[nrow][ncol] == '1'){
                dfs(grid , nrow , ncol, n , m);

            }
        }
      
  }
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int count = 0;


        for( int i = 0 ; i< n ; i++){
            for( int j =0 ; j< m ; j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(grid,i,j,n,m);
                }
            }
        }
        return count;;
    }
};
