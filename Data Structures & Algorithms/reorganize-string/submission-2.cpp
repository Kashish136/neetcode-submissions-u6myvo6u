class Solution {
public:
    string reorganizeString(string s) {
        
         priority_queue<pair<int,char>> pq;
    unordered_map<char,int> mpp;

    // count frequency
    for(char ch : s){
        mpp[ch]++;
    }

    int n = s.size();

    // feasibility check
    for(auto it : mpp){
        if(it.second > (n+1)/2){
            return "";
        }
        pq.push({it.second, it.first});
    }

    string str = "";

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        int freq = it.first;
        char ch = it.second;

        // if safe to use
        if(str.empty() || str.back() != ch){
            str += ch;
            freq--;

            if(freq > 0){
                pq.push({freq, ch});
            }
        }
        else{
            // need second best option
            if(pq.empty()) return ""; // no alternative → impossible

            auto it2 = pq.top();
            pq.pop();

            int freq2 = it2.first;
            char ch2 = it2.second;

            str += ch2;
            freq2--;

            if(freq2 > 0){
                pq.push({freq2, ch2});
            }

            // push back first character unchanged
            pq.push({freq, ch});
        }
    }

    return str;
    }
};