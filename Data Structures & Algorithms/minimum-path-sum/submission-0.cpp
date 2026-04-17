class Solution {
public:

int movement( int i , int j , int m , int n , vector<vector<int>>&dp ,
 vector<vector<int>>&grid ){

    if( i == m-1 && j == n-1){
        return grid[m-1][n-1] ;
        // one valid path found out 
    }
     
     
    if( i < 0 || j < 0 || i >= m || j >= n ){
        return 0 ;
    }


    if(dp[i][j] != -1){
        return dp[i][j];
     }

    int down = grid[i][j] + movement( i , j+1 , m , n  , dp , grid);

    int right =  grid[i][j] + movement( i+1 , j , m , n , dp , grid);

    return dp[i][j] = min(down,right) ;


   }
    int minPathSum(vector<vector<int>>& grid) {
          // out of bounds
          int m = grid.size();
          int n = grid[0].size();

          vector<vector<int>>dp( m , vector<int>( n , -1));
          return movement( 0 , 0 , m , n ,dp , grid);
        
    }
};