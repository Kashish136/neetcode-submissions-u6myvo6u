/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:

  bool isvalid(int i , int n){
     
     for( int j = 0 ; j < n ; j++){
          if(i == j){
            continue;   // if we have the same person we will ignore elsewhile
          }
        else if(knows(i,j)){
            return false;
        }
     }

     for( int k = 0 ; k < n ; k++){
        if( k == i){
            continue;
        }
        else if(!knows(k,i)){
            return false ;
        }

     }

     return true ;
  }
    int findCelebrity(int n) {

        for( int i = 0 ; i < n ; i++){
            if(isvalid(i ,n)){
                return i ;
            }
        }

        return -1;
        
    }
};
