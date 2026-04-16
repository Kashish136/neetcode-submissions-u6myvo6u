class Solution {
public:
    string reorganizeString(string s) {
         priority_queue<pair<int,char>>pq;
        // maintaining  maxheap for handling frequencies of different elements


      
        int n = s.size();
        string result = "";

        unordered_map<char,int>mpp;
        for( int i = 0 ; i < s.size() ; i++){

            char ch = s[i];
            mpp[ch]++;
        }

        for( auto it: mpp){

            if(it.second > ((n+1)/2)){
                return "" ;
            }

            else{
                pq.push({it.second , it.first});
            }
        }


        while(!pq.empty()){

            int cycle = 2;

            vector<pair<int,char>>store;
           
           while(cycle-- && !pq.empty()){
                auto top = pq.top();
                pq.pop();

                result += top.second;

                if(top.first - 1 > 0){
                    store.push_back({top.first - 1, top.second});
                }
            }

            // push back remaining chars
            for(auto &p : store){
                pq.push(p);
            }





        }

        return result ;
    }
};