class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {



        int left = 0;
        int right = 0;
        int ans = 0;
        int k = minutes ;
        int sum = 0;

        for(int right = 0 ; right < customers.size() ; right++){
             

                if(grumpy[right] == 1){
                    sum += customers[right];
                    k--;
                }
                else{
                    sum += customers[right];
                }


                if( left <= right && k < 0){
                     if(grumpy[left] == 1){
                        sum -= customers[left];
                        k++;
                        
                     }

                     left++;
                     
                }


                ans = max(ans , sum);


             
        }
        return ans ;
    }
};