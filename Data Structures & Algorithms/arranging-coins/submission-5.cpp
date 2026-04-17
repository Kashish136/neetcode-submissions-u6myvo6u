class Solution {
public:
    int arrangeCoins(int n) {
        

       int count = 0;
        int row = 1;
        while(n > row){
            count++;
            n = n-row;
            row++;
        }
        return count ;
    }
};