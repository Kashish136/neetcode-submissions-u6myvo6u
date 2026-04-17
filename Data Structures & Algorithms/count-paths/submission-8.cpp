class Solution {
public:

   int movement( int i , int j , int n , int m , vector<vector<int>>&dp){

    if( i == m-1 && j == n-1){
        return 1 ;
        // one valid path found out 
    }
     
     
    if( i < 0 || j < 0 || i >= m || j >= n ){
        return 0 ;
    }


    if(dp[i][j] != -1){
        return dp[i][j];
     }

    int down = movement( i , j+1 , n , m  , dp);

    int right = movement( i+1 , j , n , m , dp);

    return dp[i][j] = down+right ;


   }
    int uniquePaths(int m, int n) {
       
       vector<vector<int>>dp( m+1 , vector<int>(n+1 , -1));
       return dp[m-1][n-1];
        
    }
};
