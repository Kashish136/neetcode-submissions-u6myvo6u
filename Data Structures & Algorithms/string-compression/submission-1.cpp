class Solution {
public:
    int compress(vector<char>& chars) {
        
    int i = 0;
    int n = chars.size();
    int write = 0;

    while(i < n){

        char ch = chars[i];
        int count = 0;

        while(i < n && chars[i] == ch){
            i++;
            count++;
        }

        chars[write] = ch;
        write++;

        if(count > 1){
            string cnt = to_string(count);

            for(char c : cnt){
                chars[write] = c;
                write++;
            }
        }
    }

    return write;
    }
};