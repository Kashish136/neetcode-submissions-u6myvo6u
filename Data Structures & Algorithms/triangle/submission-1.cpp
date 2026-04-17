class Solution {
public:

int solve(int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        int n = triangle.size();

        // Base case: last row
        if (row == n - 1)
            return triangle[row][col];

        // Memoized
        if (dp[row][col] != -1)
            return dp[row][col];

        // Move down and down-right
        int down = triangle[row][col] + solve(row + 1, col, triangle, dp);
        int downRight = triangle[row][col] + solve(row + 1, col + 1, triangle, dp);

        // Return min path sum from this cell
        return dp[row][col] = min(down, downRight);
    }
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); // memo table
        return solve(0, 0, triangle, dp);
        
    }
};