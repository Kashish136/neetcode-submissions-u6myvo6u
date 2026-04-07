class Solution {
public:

   int movement( int i , int j , int n , int m){

    if( i == m-1 && j == n-1){
        return 1 ;
        // one valid path found out 
    }

    if( i < 0 || j < 0 || i >= m || j >= n ){
        return 0 ;
    }

    int down = movement( i , j+1 , n , m );

    int right = movement( i+1 , j , n , m);

    return down+right ;


   }
    int uniquePaths(int m, int n) {
       
       return movement(0,0,n , m);
        
    }
};
