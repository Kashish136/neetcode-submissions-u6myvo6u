class Solution {
public:
  vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};

    bool dfs(int r, int c,
             vector<vector<int>>& maze,
             vector<vector<bool>>& visited,
             vector<int>& destination) {

        // If we reached destination
        if (r == destination[0] && c == destination[1])
            return true;

        visited[r][c] = true;

        int n = maze.size();
        int m = maze[0].size();

        // Try all 4 directions
        for (int i = 0; i < 4; i++) {
            int nr = r;
            int nc = c;

            // Roll the ball until it hits a wall
            while (nr + dr[i] >= 0 && nr + dr[i] < n &&
                   nc + dc[i] >= 0 && nc + dc[i] < m &&
                   maze[nr + dr[i]][nc + dc[i]] == 0) {
                nr += dr[i];
                nc += dc[i];
            }

            // nr, nc is the stopping position
            if (!visited[nr][nc]) {
                if (dfs(nr, nc, maze, visited, destination))
                    return true;
            }
        }

        return false;}
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int n = maze.size();
        int m = maze[0].size();
vector<vector<bool>> visited(n,vector<bool>(m,false));
        return dfs(start[0],start[1],maze,visited,destination);
    }
};
