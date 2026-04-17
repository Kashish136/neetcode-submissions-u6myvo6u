class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        

        int left = 0;
        int sum = 0;
        int count = 0;
        int finalans = 0;

        for(int right = 0 ; right < arr.size() ; right++){
               
               sum += arr[right];

               while( left <= right && right-left+1 > k){
                   sum -= arr[left];
                   left++;
               }

               if(sum/(k) >=  threshold){
                count++;
                finalans = max(finalans , count);
               }
        }

        return finalans ;
    }
};