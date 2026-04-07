class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
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
    return merged;
    }
        
    
};
