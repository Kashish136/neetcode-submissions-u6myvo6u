class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        

        unordered_map<char , int>mpp;
        mpp['a'] = a;
        mpp['b'] = b;
        mpp['c'] = c;


        priority_queue<pair<int,int>>pq;
        for( auto it : mpp){
            pq.push({it.second , it.first});
        }
   
      string str = "";
       while(!pq.empty()){


       auto it1 = pq.top();
       int freq = it1.first ;
       char ch = it1.second;
       pq.pop();

       

        int length = str.size();

        if( length >=2 && str[length-1] == ch && str[length-2] == ch){


            if(pq.empty()){
                return "" ;
            }

            else{
             
             auto it2 = pq.top();
             int freq2 = it2.first;
             char ch2 = it2.second ;

             str += ch2;
             pq.pop();

             if(freq > 1){
                pq.push({freq2-1 , ch2});
             }

             pq.push({it1});
        }
        }

        else{
            str += ch1;
            if(freq1 > 0){
                pq.push({freq1 , ch1});
            }
        }


       }

       retur str;

    }
};