class Solution {
public:

int helper(vector<int>&nums , int maxi , int mini , int index , int n , int target){


   if(index == nums.size()){

       if((mini +  maxi <= target)){
          return 1 ;
       }

       return 0;
   }


   int pick = helper(nums , max(maxi , nums[index]) , min(mini , nums[index]) , index+1 , n , target);

   int not_pick = helper(nums , maxi , mini , index+1 , n , target);


   return pick + not_pick ;



}
    int numSubseq(vector<int>& nums, int target) {
        
         int n = nums.size();
        return helper(nums , INT_MIN , INT_MAX, 0, n , target);
    }
};