class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        

        int already = 0;

        for(int i = 0 ; i < customers.size() ; i++){
            int val =  customers[i];
            already += val ;
        }

        // this function represents the customers which have already been
        // satisfied which are already very happy , already in the state of joy


      // now we only wanna figure out the customers which were or are unhapy 
      // and we can satisfy them

      int extra = 0;
      int maxi = INT_MIN;
      int left = 0;

      for(int right = 0 ; right < customers.size() ; right++){
             
              if(grumpy[right] == 1){
                extra += customers[right];
            }

            if(right-left+1 > minutes){
               
               if(grumpy[left] == 1){
                extra -= customers[left];
               }
                left++;
            }

            maxi = max(maxi ,  extra);
          

      }

      return (already + maxi);
    }
};