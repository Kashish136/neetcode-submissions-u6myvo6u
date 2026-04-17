class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {

        vector<vector<int>>ans ;
        // if we want to remove an interval , then it must lie within
        // the range of the interval to be removed given to us ;

     int start = toBeRemoved[0];
     int end = toBeRemoved[1];
     // depicting the range of interval we want to remove

    for( int i = 0 ; i < intervals.size() ; i++){

        int s = intervals[i][0];
        int e = intervals[i][1];
    
    // we can only skip an interval if we have elements in a different range 
    // then the desired interval for it to be removed 


    if( s >= end || e <= start){
        ans.push_back({s ,e}); // no interval removal 
    }

    else{
        if( s  < start){
            ans.push_back({s,start});
        }
        else if( e > end){
            ans.push_back({end , e});
        }
    }


    }
        return ans ;
    }
};
