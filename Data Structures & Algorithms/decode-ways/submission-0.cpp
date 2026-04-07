class Solution {
public:

   int dfs( int i , string&s){

    if( i == s.size()){
        return 1 ;
    }

    if( s[i] == '0'){
        return 0 ;
    }

    int result = dfs(i+1 , s);

    int result2 = 0;

    if( i < s.size()-1){

        if(s[i] == '1' || (s[i] == '2' && s[i+1] <'7')){
            result2 = dfs(i+2 , s);
        }
    }

    return result+result2 ;
   }
    int numDecodings(string s) {

        return dfs( 0 , s);
        
    }
};
