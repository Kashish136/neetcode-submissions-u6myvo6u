class Solution {
public:


  vector<int>rows = {-1,1,0,0};
  vector<int>cols = {0,0,-1,1};


   void helper(vector<vector<char>>&board , int x ,int y ,
    vector<vector<bool>>&visited , int n , int m ){


        visited[x][y] = 1;

        for( int k = 0; k < 4 ; k++){
            int nrow =  x + rows[k];
            int ncol = y + cols[k];


            if( nrow >= 0 && ncol < m && ncol >= 0 && nrow < n 
            && visited[nrow][ncol] == 0 && board[nrow][ncol] == 'O'){
                visited[nrow][ncol] = 1;
                 helper(board , nrow , ncol , visited, n , m );
            }
        }



   }
    void solve(vector<vector<char>>& board) {




        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>visited( n , vector<bool>(m ,0));

        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < m ; j++){
                if( i == 0 || j == 0 || i == n-1 || j == m-1){

                    if(!visited[i][j] && board[i][j] == 'O'){
                        helper(board , i, j , visited , n , m);
                    }
                }
            }
        }


        for( int i = 0  ; i < n ; i++){
            for( int j = 0 ; j < m ; j++){
                if(board[i][j] == 'O' && visited[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }
      
    }
};
