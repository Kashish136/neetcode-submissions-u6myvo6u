class Solution {
public:


vector<int>rows = {-1,1,0,0};
vector<int>cols = {0,0,-1,1};

  int dfs(vector<vector<int>>&grid , int i , int j , int n 
  , int m ){

      grid[i][j] = 0;
      int value = 1;
      
    

      for(int k = 0 ; k < 4 ; k++){

            int nrow = i + rows[k];
            int ncol = j + cols[k];

            if( nrow >= 0 && ncol < m && ncol >= 0 && nrow < n 
            && grid[nrow][ncol] == 1){
               value += dfs( grid , nrow , ncol , n ,  m);
            }
      }

      return value;
  }
    int maxAreaOfIsland(vector<vector<int>>& grid) {


        int n = grid.size();
        int m = grid[0].size();



        int maxarea = 0;

        for( int i = 0 ;i < n ; i++){
            for( int j = 0 ; j < m;j++){
                if(grid[i][j] == 1){
                    int area = dfs(grid, i , j , n , m);
                    
                    maxarea = max(area, maxarea);
                    
                }
            }
        }
        return maxarea;
    }
};
