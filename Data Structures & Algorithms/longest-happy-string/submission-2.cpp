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

        string ans = "";

    void solve(int a, int b, int c, string curr) {

        // update best answer
        if(curr.size() > ans.size()){
            ans = curr;
        }

        int n = curr.size();

        // try 'a'
        if(a > 0){
            if(n < 2 || !(curr[n-1] == 'a' && curr[n-2] == 'a')){
                solve(a-1, b, c, curr + 'a');
            }
        }

        // try 'b'
        if(b > 0){
            if(n < 2 || !(curr[n-1] == 'b' && curr[n-2] == 'b')){
                solve(a, b-1, c, curr + 'b');
            }
        }

        // try 'c'
        if(c > 0){
            if(n < 2 || !(curr[n-1] == 'c' && curr[n-2] == 'c')){
                solve(a, b, c-1, curr + 'c');
            }
        }
    }

    string longestDiverseString(int a, int b, int c) {
        solve(a, b, c, "");
        return ans;
    }

};