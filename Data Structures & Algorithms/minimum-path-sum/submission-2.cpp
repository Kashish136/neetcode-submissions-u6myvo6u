class Solution {
public:

int movement( int i , int j , int m , int n , vector<vector<int>>&dp ,
 vector<vector<int>>&grid ){



   // out of bounds → invalid path
        if (i >= m || j >= n)
            return 1e9;



    if( i == m-1 && j == n-1){
        return grid[m-1][n-1] ;
        // one valid path found out 
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
          for(int i = 0 ; i < n ; i++){
            dp[0][i] = grid[0][i] ;
          }


          for( int i = 1 ; i < m ; i++){
            for( int j = 0 ; j < n ; j++){

                int up = 1e9;
                if(i>0)
                up = grid[i][j] + dp[i-1][j];

                int down = 1e9;
                if( j > 0)
                down = grid[i][j] + dp[i][j-1];

             dp[i][j] = min(up , down);
            }
          }
          return dp[m-1][n-1];
        
    }
};