class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {


        vector<vector<int>>ans ;

        int i = 0;
        int j = 0;
        int n = firstList.size();
        int m = secondList.size();

        while( i < n && j < m ){
            int val1 = firstList[i][0];
            int val2 = firstList[i][1];
            int val3 = secondList[j][0];
            int val4 = secondList[j][1];
            ans.push_back({val3 , val2});
            

            if(i+1 < n && firstList[i+1][0] == val4){
                ans.push_back({val4 , val4});
                j++;

            }
            else{
                j++;
            }
           
           i++;
           
        }
        return ans ;
    }
};