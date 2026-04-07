class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

                vector<vector<int>> res;
        int i = 0, j = 0;

        while (i < firstList.size() && j < secondList.size()) {
            int startA = firstList[i][0], endA = firstList[i][1];
            int startB = secondList[j][0], endB = secondList[j][1];

            int start = max(startA, startB);
            int end = min(endA, endB);

            if (start <= end) {
                res.push_back({start, end});
            }

            if (endA < endB) {
                i++;
            } else {
                j++;
            }
        }
return res;

        
    }
};