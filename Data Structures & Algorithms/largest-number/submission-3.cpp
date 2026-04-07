class Solution {
public:

   bool static comp(string&a , string&b){
     
       return (a+b) > (b+a);

   }


    string largestNumber(vector<int>& nums) {
      

      vector<string>arr;

      for(int i = 0 ; i < nums.size() ; i++){
         
           int num = nums[i];
           string str = to_string(num);
           arr.push_back(str);
      }


      sort(arr.begin() , arr.end() , comp);

      
        // Edge case: if largest is "0"
        if (arr[0] == "0") return "0";


      string output = "";

      for(string&st : arr){
          output +=st;
      }



       return output ;
        
    }
};