class Solution {
public:
  

  int f( vector<int>&output , int index  , int target){

   if( index == 0){
    if( target%output[0]){
        return target/output[0];
    }
    else{
        return 1e9 ;
    }
   }

    int not_take = 0 + f( output , index-1 , target);
    int take = INT_MAX;

    if( output[index] <= target)
      
    take = 1 + f(output , index , target-output[index] );

    return min(take , not_take );

  }
    int numSquares(int n) {
        
        vector<int>output ;
        for( int i =1 ; i*i <= n ; i++){
            output.push_back(i);
        }

        int p = output.size();

        // at first we will be maintaining a vector for handling perfect squares

        return f( output , p-1 , n);
    }
};