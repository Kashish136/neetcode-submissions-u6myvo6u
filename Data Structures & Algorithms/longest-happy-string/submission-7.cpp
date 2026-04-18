class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
         unordered_map<char, int> mpp;
    mpp['a'] = a;
    mpp['b'] = b;
    mpp['c'] = c;

    priority_queue<pair<int,char>> pq;

    for(auto it : mpp){
        if(it.second > 0){
            pq.push({it.second, it.first});
        }
    }

    string str = "";

    while(!pq.empty()){

        auto it1 = pq.top();
        pq.pop();

        int freq = it1.first;
        char ch = it1.second;

        int len = str.size();

        // if last two chars are same as current → can't use
        if(len >= 2 && str[len-1] == ch && str[len-2] == ch){

            if(pq.empty()) break;

            auto it2 = pq.top();
            pq.pop();

            int freq2 = it2.first;
            char ch2 = it2.second;

            // use second best
            str += ch2;
            freq2--;

            if(freq2 > 0){
                pq.push({freq2, ch2});
            }

            // push back first char unchanged
            pq.push({freq, ch});
        }
        else{
            str += ch;
            freq--;

            if(freq > 0){
                pq.push({freq, ch});
            }
        }
    }

    return str;
    }
};