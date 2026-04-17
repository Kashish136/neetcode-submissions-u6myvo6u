class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int>rowcount(n,0);
        vector<int>colcount(m,0);
        int total = 0;

        for( int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    total++;
                    rowcount[i]++;
                    colcount[j]++;
                }
            }
        }


   

     int total = 0;

     for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if (grid[i][j] == 1 && (rowCount[i] > 1 || colCount[j] > 1)) {
    total++;
}
        }
     }

     return total ;
    }
};