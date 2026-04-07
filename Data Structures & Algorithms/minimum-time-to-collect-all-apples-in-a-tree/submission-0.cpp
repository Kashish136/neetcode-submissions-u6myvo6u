class Solution {
public:

   int dfs(vector<vector<int>>&adj , vector<bool>&hasApple
    , int current , int parent ){


        int time = 0;

        for(int child : adj[current]){
            if(child == parent){
                continue ;
            }
            int childtime = dfs(adj , hasApple , child , current);

            if(childtime > 0 || hasApple[child]){
                 time += 2 + childtime ;
            }
        }





        return time;
    }



    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        

        vector<vector<int>>adj(n);

        for( auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // we have built an adjacency list now
        
        int k = 0 ;
        for(int i = 0 ; i < hasApple.size() ; i++){
             if(hasApple[i] == true){
                k++;
             }
        }

        // it represents the count of each 
        //and every apple present in the hasApple list
      return dfs(adj , hasApple , 0 , -1);
        
    }
};