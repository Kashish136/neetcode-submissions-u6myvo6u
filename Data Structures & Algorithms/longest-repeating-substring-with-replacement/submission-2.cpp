class Solution {
public:
    int characterReplacement(string s, int k) {


        int left = 0;
      //  int right = 0;

        int n = s.size();

        unordered_map<char,int>mpp;


        // for(int i = 0 ; i < s.size() ; i++){
        //     char ch = s[i];
        //     mpp[ch]++;
        // }

       // unordered_map<char,int>mpp;
        int maxfreq = 0;
        int output = 0;


        for(int right = 0 ; right < n ; right++){

            char ch = s[right];
            mpp[ch]++;
            maxfreq = max(maxfreq , mpp[ch]);



            while((right-left+1)-maxfreq > k){
                mpp[s[left]]--;
                left++;
            }

            output = max(output , right-left+1);




        }

        return output ;
        
    }
};
