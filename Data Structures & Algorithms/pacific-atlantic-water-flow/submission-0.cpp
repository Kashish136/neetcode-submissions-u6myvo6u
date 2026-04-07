class Solution {
public:

  vector<int>rows = {-1,1,0,0};
  vector<int>cols = {0,0,-1,1};


  bool isvalid(int i , int j, vector<vector<int>>&heights , int n , int m){


    vector<vector<bool>>visited( n , vector<bool>(m,false));

       queue<pair<int,int>>q;

       bool atlantic = false ;
       bool pacific = false ;
         
         q.push({i,j});
         visited[i][j] = 1;

         while(!q.empty()){

            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            if(x == 0 || y == 0){
                pacific = true ;
            }

            if( x == n-1 || y == m-1){
                atlantic = true ;
            }

            if(pacific && atlantic){
                return true ;
            }

            for( int k = 0; k < 4 ; k++){
                int nrow = x+rows[k];
                int ncol = y + cols[k];

                if(nrow >= 0  && nrow < n && ncol >=0 && 
                ncol < m && !visited[nrow][ncol] && heights[nrow][ncol]<= heights[x][y]){
                    q.push({nrow,ncol});
                    visited[nrow][ncol] = true ;
                }
            }

         }

         return false ;
  }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        

        // so basically if from each cell it can reach a point where 
        // it can come upto the last row and last column 
        //or the first row and first column , then that part can be added to the ans 
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>ans;

        for( int i = 0 ; i < n ; i++){
            for( int j = 0  ; j < m ; j++){
                int coordinate = heights[i][j] ;
                if(isvalid(i,j,heights, n , m)){
                    vector<int>output = {i,j};
                    ans.push_back(output);
                }
            }
        }

        return ans ;
    }
};
