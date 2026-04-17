class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
             int left = 0;
             int sum = 0;
             int maxlen = 0;
             int output = INT_MAX;


             for(int i = 0 ; i < nums.size() ;i++){
                  sum += nums[i];
                  while( sum >= target){
                     output = min(output , maxlen);
                     sum -= nums[left];
                     left++;
                  }
             }
         return output ; 
    }
};