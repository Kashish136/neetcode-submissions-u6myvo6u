class Solution {
public:



//   int minimum( vector<vector<int>>costs , vector<vector<bool>>&visited , int index){
//     int ans  = INT_MAX;
//    if( index == 0){

//     for(int i = 0 ; i<3 ; i++){
//         if(visited[index+1][i] == false){
//             ans = min(ans , costs[index][i]);
//         }

//     }
//      return ans ; // base case ;
//    }

//      int blue = INT_MAX ;
//      if( visited[index+1][2] == false){
//         visited[index][2] = true ;
//         blue = costs[index][2] + minimum(costs , visited , index-1);
//         visited[index][2] = false ;
//      }

//           int green = INT_MAX ;
//      if( visited[index+1][1] == false){
//         visited[index][1] = true ;
//         green = costs[index][1] + minimum(costs , visited , index-1);
//         visited[index][1] = false ;
//      }
    

//         int red = INT_MAX ;
//      if( visited[index+1][0] == false){
//         visited[index][0] = true ;
//         red = costs[index][0] + minimum(costs , visited , index-1);
//         visited[index][0] = false ;
//      }



//      return min(blue , min(green , red));
    
//   }

  







    int minCost(vector<vector<int>>& costs) {
        
    
    int n = costs.size();

   //  if( n == 1){
   //      return min(costs[0][0] , min(costs[0][1] , costs[0][2]));
   //  }

    // first base case which we  are trying to handle 

    vector<vector<int>>dp( n , vector<int>(3,0));

    for( int i = 0 ; i < 3 ; i++){

      dp[0][i]= costs[0][i];

    }

    for( int i = 1 ; i < n ; i++){

   dp[i][0] = costs[i][0] + min(dp[i-1][1] , dp[i-1][2]);
   dp[i][1] = costs[i][1] + min(dp[i-1][2] , dp[i-1][0]);
   dp[i][2] = costs[i][2] + min(dp[i-1][1] , dp[i-1][0]);
    }



    return min(dp[n-1][0] , min(dp[n-1][1] , dp[n-1][2]));








    }
};