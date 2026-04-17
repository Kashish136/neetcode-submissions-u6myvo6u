class Solution {
public:
    int arrangeCoins(int n) {


        if(n%2 == 0) return ceil(sqrt(n));
        else
        return floor(sqrt(n));
        
    }
};