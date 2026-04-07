class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {


        vector<vector<int>> ans;

        for (auto &it : intervals) {

            // Case 1: current interval is completely before newInterval
            if (it[1] < newInterval[0]) {
                ans.push_back(it);
            }

            // Case 2: current interval is completely after newInterval
            else if (it[0] > newInterval[1]) {
                ans.push_back(newInterval);
                newInterval = it;
            }

            // Case 3: overlapping intervals
            else {
                newInterval[0] = min(newInterval[0], it[0]);
                newInterval[1] = max(newInterval[1], it[1]);
            }
        }

        // push the last interval
        ans.push_back(newInterval);

        return ans;
        
    }
};
