class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        

        vector<vector<pair<int,int>>>adjacency(n);


        const int INF = 1e9;
        vector<int>distance(n,INF);
        distance[src] = 0;
        for(auto it: flights){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adjacency[u].push_back({v,wt});
        }


        priority_queue<tuple<int,int,int> , vector<tuple<int,int,int>>,
        greater<tuple<int,int,int>>>pq;


        //we have defined the priority_queue based on // distance,tuple,cost

        pq.push({0,0,src});

        while(!pq.empty()){

            auto[cost,stops,node] = pq.top();
            pq.pop();

            if(stops >= k){
                continue;
            }

            for( auto[adjn , price] : adjacency[node]){
                  
                  if(cost+price < distance[adjn]){
                    distance[adjn] = cost + price;
                    pq.push({cost+price,stops+1,adjn});
                  }
            }

        }

        if(distance[dst] != INF){
            return distance[dst];
        }

        return -1;
    }
};
