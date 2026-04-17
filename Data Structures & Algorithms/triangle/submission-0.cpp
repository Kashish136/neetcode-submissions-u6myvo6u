class Solution {
public:

 // so basically we need to track the index number also along with the 
 // row and column number ....
   int minpath( vector<vector<int>>&triangle , int row , int index , int j   , int n){
           
          
            if( index == n-1){ // when we reach the final index

            int value = triangle[index][j];
             int ans = INT_MAX;

            if(j+1 < row){
                ans = triangle[index][j+1];
            }

             return min( value , ans ) ;

            }
            

        int key = triangle[index][j] + minpath(triangle , row+1 , index+1  ,j , n);
            int key2 = INT_MAX;

            if( j+1 <= row){

     key2 = triangle[index][j+1] + minpath(triangle , row+1 , index+1 , j+1 , n);
            }

     return min(key , key2);

   }

    int minimumTotal(vector<vector<int>>& triangle) {
        

        int n = triangle.size();
        // because we are developing a triangle 
        return minpath(triangle , 0 , 0 , 0 , n );
      
        
    }
};