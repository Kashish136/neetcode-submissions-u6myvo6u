class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
      int value = left ;
        for( int i = left+1 ; i <= right ; i++){
            value = value&i;
        }

        return value ;
    }
};