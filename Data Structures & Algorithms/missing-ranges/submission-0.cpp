class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {

        int lowerrange = lower;
        int upperrange = -1;


        vector<vector<int>>ans ;

        for(int i =0 ; i < nums.size() ; i++){
            if(nums[i] == lowerrange){
                lowerrange++; // once we have found a certain element we will
                // increment the value of lowerrange coz we dont want to carry it forward
            }
            else{

                vector<int>fr;
            auto it = upper_bound(nums.begin(), nums.end(), lowerrange);
              if (it != nums.end()){
                  int value = *it ;
                  fr.push_back(lowerrange+1);
                  fr.push_back(value-1);
                  ans.push_back(fr); }
            
            else if (it == nums.end()){
                  int value = upper ;
                  fr.push_back(lowerrange+1);
                  fr.push_back(upper);
                  ans.push_back(fr);
            }

            }
        }
   return ans ;
        
    }
};
