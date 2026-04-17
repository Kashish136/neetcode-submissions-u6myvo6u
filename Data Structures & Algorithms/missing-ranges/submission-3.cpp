class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {


        vector<vector<int>>ans ;
        
        if(nums.empty() && lower == upper){
            vector<int>fr;
            fr.push_back(lower);
            fr.push_back(upper);
            ans.push_back(fr);

        }

        int prev = lower ;
        for( int i = 1 ; i < nums.size() ; i++){
            int num1 = nums[i];
            if(num1-prev != 1){
                vector<int>fr;
                fr.push_back(prev+1);
                fr.push_back(num1-1);
                ans.push_back(fr);
                prev = num1;

            }
            else{
                prev = num1;
            }
        }

        if(prev != upper){
            vector<int>fr;
            int key1 = prev+1;
            int key2 = upper ;

            fr.push_back(key1);
            fr.push_back(key2);
            ans.push_back(fr);
        }
        return ans ;
    }
};
