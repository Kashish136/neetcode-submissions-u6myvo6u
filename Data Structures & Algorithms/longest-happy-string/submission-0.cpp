class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
          string result = "";

        while(true){

            // sort manually (3 values only → cheap)
            vector<pair<int,char>> v = {
                {a,'a'}, {b,'b'}, {c,'c'}
            };

            sort(v.begin(), v.end(), greater<>());

            bool added = false;

            for(auto &p : v){
                int count = p.first;
                char ch = p.second;

                if(count == 0) continue;

                int len = result.size();

                // ❗ avoid 3 consecutive
                if(len >= 2 && result[len-1] == ch && result[len-2] == ch){
                    continue;
                }

                // place character
                result += ch;

                // reduce count
                if(ch == 'a') a--;
                else if(ch == 'b') b--;
                else c--;

                added = true;
                break;
            }

            if(!added) break;
        }

        return result;
    }
};