class Solution {
public:
    int missingNumber(vector<int>& arr) {
        


        
//         int n = arr.size();
//         int diff = (arr[n-1]-arr[0])/n;
//         vector<int>nums ;
//         nums.push_back(arr[0]);
//         int final = arr[n-1]-arr[0];

//         if(arr[0] == arr[arr.size()-1]) {
//     return arr[0]; // the missing number is the repeated value
// }


//         int val = arr[0];
//         while(final != 0){
            
//             int key = val+diff;
//             nums.push_back(key);
//             final = final-diff;
//             val = key ;

//         }


//         int output = 0;

//         for(int i = 0 ; i < arr.size() ; i++){
//             output = output^(arr[i]);
//         }


//         for(int i = 0 ; i < nums.size() ; i++){
//             output = output^(nums[i]);
//         }
//   return output ;


     int n = arr.size();

     int low = 0;
     int high = arr.size()-1;

     while(low < high){
        int mid = low + (high-low)/2;
        if(arr[mid] == arr[0]+mid*difference){
            low = mid+1;
        }
        else{
            high = mid ;
        }
     }




     return arr[0]+difference*low;
    }
};
