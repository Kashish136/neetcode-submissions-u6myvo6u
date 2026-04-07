class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {

        vector<vector<int>> ans;

        // ✅ Fix 1: handle empty array fully
        if (nums.empty()) {
            ans.push_back({lower, upper});
            return ans;
        }

        // ✅ Fix 2: prev should represent last covered value
        long prev = (long)lower - 1;

        // ✅ Fix 3: loop must start from i = 0
        for (int i = 0; i < nums.size(); i++) {

            int num1 = nums[i];

            // ✅ Fix 4: ignore numbers outside range
            if (num1 < lower) continue;
            if (num1 > upper) break;

            // ✅ Fix 5: correct gap condition
            if (num1 > prev + 1) {
                vector<int> fr;
                fr.push_back(prev + 1);
                fr.push_back(num1 - 1);
                ans.push_back(fr);
            }

            prev = num1;
        }

        // ✅ Fix 6: final range
        if (prev < upper) {
            vector<int> fr;
            fr.push_back(prev + 1);
            fr.push_back(upper);
            ans.push_back(fr);
        }

        return ans;
        
    }
};
