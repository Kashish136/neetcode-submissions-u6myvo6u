class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        

        sort(trips.begin() , trips.end() , [](const vector<int>&a , 
        const vector<int>&b){
            return a[1] < b[1];
        });

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<
        int,int>>>pq;
        int current = 0;

        for( const auto&trip : trips){

            int cp = trip[0];
            int startTime = trip[1];
            int end = trip[2];

        while(!pq.empty() && pq.top().first <= startTime){

           
            current -= pq.top().second;
            pq.pop();
        }

        current += cp;
        if( current > capacity){
            return false ;
        }

        pq.push({end , cp});

    }
    

    return true ;

    }
};