class Solution {
public:

  bool isvalid(int n){

    for(int i = 0 ; i*i <= n ; i++){
        if(i*i == n){
            return true ;
        }
    }

    return false ;
  }
    int arrangeCoins(int n) {


        if(n%2 == 0) return ceil(sqrt(n));

        else if(isvalid(n)) return sqrt(n);
        else
        return floor(sqrt(n));
        
    }
};