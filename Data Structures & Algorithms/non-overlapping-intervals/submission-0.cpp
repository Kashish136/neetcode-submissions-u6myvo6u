class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {


        //we are performing sorting operations based on the 

        sort( intervals.begin() , intervals.end());
        int count = 0;
        int prevstart = intervals[0][0];
        int prevend = intervals[0][1];

        for( int i = 1 ; i < intervals.size() ; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if( start < prevend){
                count++;
            }
            else{
                prevstart = start ;
                prevend = end ;
            }
        }

  return count ;
        
    }
};
