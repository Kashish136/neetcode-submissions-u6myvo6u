

class Solution {
public:
    int movement(int i, int j, int m, int n, vector<vector<int>>& dp , vector<vector<int>>&obstacleGrid) {



  // out of bounds
        if (i >= m || j >= n || obstacleGrid[i][j] == 1)
            return 0;
        // destination
        if (i == m-1 && j == n-1)
            return 1;

      

        // memoized
        if (dp[i][j] != -1)
            return dp[i][j];

        int right = movement(i, j+1, m, n, dp ,obstacleGrid);
        int down  = movement(i+1, j, m, n, dp , obstacleGrid);

        return dp[i][j] = right + down;
    }

    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return movement(0, 0, m, n, dp ,obstacleGrid);
        
    }
};