class Solution {
public:
    string largestNumber(vector<int>& nums) {


        string ans = "";

        sort(nums.begin() , nums.end());

        for(int i = 0 ; i < nums.size() ; i++){

            int val = nums[i];
            string str = to_string(val);
            ans += str;
        }


        return ans ;
        
    }
};