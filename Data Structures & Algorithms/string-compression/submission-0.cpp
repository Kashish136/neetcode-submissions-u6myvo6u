class Solution {
public:
    int compress(vector<char>& chars) {


        int i = 0;
        int n = chars.length();
        int k = 0;

        while( i < n){


            char ch = chars[i];
            
            int count = 0;
           

            while( i < n && chars[i] == ch){
                 
                 i++;
                 count++;
            }

            chars[write] = current;
            write++;

            if( count > 1){
                string cnt = to_string(count);
                for(char c : count){
                    chars[write] = c;
                    write++;
                }
            }
        }

        return write;
        
    }
};