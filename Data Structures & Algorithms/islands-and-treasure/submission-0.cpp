class Solution {
public:

 
  vector<int>rows = {-1,1,0,0};
  vector<int>cols = {0,0,-1,1};


    void islandsAndTreasure(vector<vector<int>>& grid) {





        int n = grid.size();
        int m = grid[0].size();
        

        vector<vector<bool>>visited( n , vector<bool>(m,0));

      queue<pair<int,pair<int,int>>>q;
      // we are decalring queue of that size 
        for( int i = 0 ; i < grid.size() ; i++){
            for( int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 0){
                    q.push({0,{i,j}});
                    visited[i][j] = 1;

                }
            }
        }


       
        // initially we are handling all the nodes with zero as distance

        while(!q.empty()){

            auto it = q.front();
            int distance = it.first;
            int x = it.second.first;
            int y = it.second.second;
            q.pop();



            for( int k = 0 ; k < 4 ; k++){
                 
                 int nrow = x + rows[k];
                 int ncol = y + cols[k];


                 if( nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                 !visited[nrow][ncol] && grid[nrow][ncol] == INT_MAX){

                    visited[nrow][ncol] = 1;
                    grid[nrow][ncol] = distance+1;
                    q.push({distance+1 , {nrow,ncol}});

                 }
            }

        }
    }
};
