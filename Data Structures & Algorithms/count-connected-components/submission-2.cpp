class Solution {
public:
  
  class DisjointSet{

    vector<int>parent;
    vector<int>size;

// while declaring classes make sure to not have private classes 
// either declare them in public format 
// or declare them in struct format
public:
    DisjointSet(int n){
        size.resize(n+1,0);
        parent.resize(n+1,0);

        for( int i = 0 ; i <= n ; i++){
            parent[i] = i;
        }
// initially declaring the parent of each node as the node itself
    }

    int findUpar(int node){
        if(node == parent[node]){
            return node ;
        }

        return parent[node] = findUpar(parent[node]);
    }


    void unionByRank(int u , int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(ulp_u == ulp_v){
            return ;
        }

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }

        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
  };
    int countComponents(int n, vector<vector<int>>& edges) {
       
       DisjointSet ds(n);
       int count = 0;
       for( auto it : edges){
           
            int u = it[0];
            int v = it[1];
           ds.unionByRank(u,v);
        }

        for(int i = 0 ; i < n ; i++){
            if(ds.findUpar(i) == i){
                count++;
            }
        }
       return count ;
    }
};
