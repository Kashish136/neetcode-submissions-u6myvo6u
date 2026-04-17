class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int left = 0;
        int ans = 0;
        int output = 0;
        
        unordered_map<int,int>mpp;

        for(int right = 0 ; right < fruits.size() ; right++){

            int fruit = fruits[right];
            ans++;


            while(mpp.size() > 2){
                mpp[fruits[left]]--;
                if(mpp[fruits[left]] == 0){
                    mpp.erase(fruits[left]);
                }

                ans--;

                left++;
            }

            mpp[fruit]++;
          
          output = max(output , ans);

        }
        return output ;
    }
};