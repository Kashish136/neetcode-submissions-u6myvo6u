class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {



        int n = s.size();

        vector<vector<int>>intervals;

        for( string word : words){
            int start = s.find(word);
            while( start != string :: npos){
                intervals.push_back({ (int)start , (int)(start+word.size())});
                start = s.find(word , start+1);
        
        // therefore we need to keep in mind these factors 
        // that we need to track the indexes of the positions we wanna find our 
        // answer for 
        // once we have done one search its time to move on to the next
            }
            }
            if (intervals.empty()) return s; // no matches
        

            // now we will be performing merging on intervals , 
            // coz now we have tracked events...
            sort( intervals.begin() , intervals.end());

   // based on the sequence of words




            int star = intervals[0][0];
            int e = intervals[0][1];
            vector<vector<int>>merged;
            merged.push_back({star,e});

// we have initially performed pushing of initial events ;

             
            for( int i = 1 ; i < intervals.size() ; i++){

                int cs = intervals[i][0];
                int ce = intervals[i][1];



    if( cs <= merged.back()[1]){
        merged.back()[1] = max(merged.back()[1] , ce);


        // thats how we are performing modifcations , like yk , we
        // are performing it this way , that if we have less than this 
        // as an interval then we will push back the highest one
    }

    else{
        merged.push_back(intervals[i]);
    }




                

    }
        
    string ans = "";
        int idx = 0;

        for (int i = 0 ; i < merged.size() ; i++) {

            int start = merged[i][0];
            int end = merged[i][1];
            ans += s.substr(idx, start - idx);          // normal characters
            ans += "<b>" + s.substr(start, end - start) + "</b>"; // bold characters
            idx = end;
        }

        ans += s.substr(idx); // remaining characters after last interval

        return ans;






            
        
        
    }
};
