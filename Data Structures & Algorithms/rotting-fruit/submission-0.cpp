class Solution {
public:

  vector<int>rows = {-1,1,0,0};
  vector<int>cols = {0,0,-1,1};


    int orangesRotting(vector<vector<int>>& grid) {


        // see this problem is of bfs pattern coz of obvious reasons 
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>visited(n , vector<int>(m,0));

        queue<pair<int, pair<int ,int>>>q;

        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({0,{i,j}});
                }
            }
        }
        
        // it represents that a time t = 0 , we have all the elements in the 
//queue which are rotten at time t = 0;

    int mintime = 0;
      while(!q.empty()){


        auto it = q.front();
        mintime = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        visited[x][y] = 1;
        q.pop();

        for( int i = 0 ; i < 4 ; i++){

            int nrow = x + rows[i];
            int ncol = y + cols[i];

            if( nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            grid[nrow][ncol] == 1  && visited[nrow][ncol] == 0){
                q.push({mintime+1 ,{nrow , ncol}});
                grid[nrow][ncol] = 2;
            }
        }


      }



      for( int i = 0;i < n; i++){
        for( int j = 0 ; j < m ; j++){
            if(grid[i][j] == 1){
                return -1;
            }
        }
      }
      
   return mintime ;

    }
};
