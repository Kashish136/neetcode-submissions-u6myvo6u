class Solution {
public:
    int appendCharacters(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        int i = 0;
        int j = 0;
        int count = 0;

        while( i < n){

            if(s[i]== t[j]){
                i++;
                j++;
            }
            else{
                i++;
            }

        }

        return m-j;
    }
};