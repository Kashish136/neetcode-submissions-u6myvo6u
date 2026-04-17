class Solution {
public:


vector<int>rows = {-1,1,0,0};
vector<int>cols = {0,0,-1,1};

  bool helper(vector<int>&destination , vector<int>&start , int n , int m 
  ,int i , int j , vector<vector<int>>&maze , vector<vector<int>>&visited){

     if(i==destination[0] && j==destination[1]){
        return true;
     }

     visited[i][j] = true ;

     for(int k = 0 ; k < 4 ; k++){
        int nrow = i + rows[k];
        int ncol = j + cols[k];

        if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m
        && !visited[nrow][ncol] && maze[nrow][ncol] == 0){
             helper(destination,start,n,m,nrow,ncol,maze,visited);
        }
     }

     return false ;
  }
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        


        int n = maze.size();
        int m = maze.size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int i = start[0];
        int j = start[1];

        return helper(destination,start,n,m,0,0,maze,visited);


    }
};
