class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        

        for(int i = 0 ; i < strs[0].size() ; i++){
             char ch = strs[0][i];

            for(int j = 0 ; j < strs.size() ; j++){

                 char ch2 = strs[j][i];

                 if(ch2 != ch){
                    return strs[0].substr(0,i);
                 }
            }
        }

        return strs[0];
    }
};