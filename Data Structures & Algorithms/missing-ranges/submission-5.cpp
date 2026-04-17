class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {

        unordered_set<int> st(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int i = lower;

        while (i <= upper) {

            // If number exists, skip it
            if (st.count(i)) {
                i++;
                continue;
            }

            // Start of a missing range
            int start = i;

            // Move until numbers are missing
            while (i <= upper && !st.count(i)) {
                i++;
            }

            int end = i - 1;
            ans.push_back({start, end});
        }

        return ans;

        
    }
};
