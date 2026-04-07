class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int left = 0;
        int maximum = 0;

        unordered_map<int,int>mpp;

        for(int right = 0 ; right < s.size() ; right++ ){



            char ch = s[right];

            while(mpp.find(ch) != mpp.end()){
                  
                
                    mpp[s[left]]--;

                    if(mpp[s[left]] == 0){
                        mpp.erase(s[left]);
                    }

                    left++;
                
                
            }
            
            mpp[ch]++;
            int length = right-left+1;
            maximum = max(maximum , length);

            
        }

        return maximum ;
        
    }
};
