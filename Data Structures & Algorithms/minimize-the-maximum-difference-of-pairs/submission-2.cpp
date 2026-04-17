class Solution {
public:

 bool isvalid(int mid , int p , vector<int>&nums){

    int count = 0;
    int i = 0;

    // for(int i = 0 ; i < nums.size()-1 ; i++){
    //     for( int j = i+1 ; j < nums.size() ; j++){

    //         int value = abs(nums[i]-nums[j]);
    //         if(value <= mid){
    //             count++;
    //         }
    //     }
    // }
    // if(count == p){
    //     return true ;
    // }
    // return false ;
  

  while( i < nums.size()-1){
      
      int val = nums[i];
      int key = nums[i+1];
      if(abs(key-val) <= mid){
         count++;
         i+=2;

      }
      else{

        i +=1;
      }
  }

  if( count == p){
    return true ;
  }


  return false ;
 }
    int minimizeMax(vector<int>& nums, int p) {
        int low = *min_element(nums.begin() , nums.end());
        int value = *max_element(nums.begin() , nums.end());

        int high = value-low;

      
      int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(isvalid(mid , p , nums)){

                ans = mid ;
                high = mid-1;

            }
            else{
                 low = mid+1;
            }
        }
        return ans ;

        // since we are trying to minimze the maximum difference 
        // therefore our main goal is performing minimizations 
        // therfore i end up taking amid value and try to minimize it 
    }
};