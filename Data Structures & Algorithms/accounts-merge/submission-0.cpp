class disjoint_set{
    vector<int> size, parent;
public:
 disjoint_set( int n){
    size.resize(n , 1);
    parent.resize(n);
    for( int i =0 ; i < n ;i++){
        parent[i] =i;
    }
 }

    int findupar( int node){
        if( node == parent[node]){
            return node;
        }
        return parent[node] = findupar( parent[node]);
    }
    void unionbysize( int u , int v){
        int ulpu = findupar(u);
        int ulpv = findupar(v);
        if( ulpu == ulpv) return ;

        if( size[ulpu ] < size[ulpv]){
            parent[ulpu] = ulpv;
            size[ulpv]+= size[ulpu];
        }
        else if( size[ulpv] < size[ulpu]){
            parent[ulpv] = ulpu;
            size[ulpu]+= size[ulpv];
        }
        else{
            parent[ulpv] = ulpu;
            size[ulpu] += size[ulpv];
        }
    }
 };













class Solution {

public:


    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
         
        
        int n = accounts.size();
        disjoint_set ds(n);
         unordered_map<string , int>mpp;

         for( int i = 0 ; i < accounts.size() ; i++){
            for( int j = 1 ; j < accounts[i].size() ; j++){
                  
                  string email = accounts[i][j];
                if(mpp.find(email) == mpp.end()){
                    mpp[email] = i ;
                }
                else{
                    ds.unionbysize(i,mpp[email]);
                }
            }
         }



         // now since we have performed union it implies that we h
      // have connected nodes which are directly or indirectly
      // linked with each other
        
        vector<vector<string>>merged(n);
        for( auto it : mpp){
            string str = it.first;
            int value = ds.findupar(it.second);

            merged[value].push_back(str);
        }

        vector<vector<string>>ans ;
        for( int i =0 ; i < n ; i++){
            if(merged[i].size() == 0){
                
                continue;
            }
            sort(merged[i].begin() , merged[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            temp.insert(temp.end() , merged[i].begin() , merged[i].end());
            ans.push_back(temp);
        }
        sort(ans.begin() , ans.end());
        return ans ;
    }
};