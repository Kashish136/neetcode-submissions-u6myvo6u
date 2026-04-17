class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

    vector<int>rows = {-1,1,0,0};
    vector<int>cols = {0,0,-1,1};

        int n = heights.size();
        int m = heights[0].size();
        const int INF = 1e9;

        priority_queue<pair<int,pair<int,int>> , 
        vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>pq;

   vector<vector<int>>distance(n,vector<int>(m,1e9));

        pq.push({0,{0,0}});

        while(!pq.empty()){
             auto it = pq.top();
             int effort = it.first;
             int x = it.second.first;
             int y = it.second.second;
             pq.pop();


        for( int i = 0 ; i < 4 ; i++){
            int nrow = x + rows[i];
            int ncol = y + cols[i];


            if( nrow >= 0 && ncol < m && ncol >= 0 && nrow < n){

            int output =  abs(heights[x][y]-heights[nrow][ncol]);
            int neweffort = max(effort , output);

            if(neweffort < distance[nrow][ncol]){
                pq.push({neweffort,{nrow,ncol}});
                distance[nrow][ncol] = neweffort;
            }
        }

        }

        }

        return (distance[n-1][m-1]);
        
    }
};