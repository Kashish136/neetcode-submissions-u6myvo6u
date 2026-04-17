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
           arr.push_back(num);
      }


      sort(arr.begin() , arr.end() , cmp);

      string output = "";

      for(string&str : arr){
          output +=str;
      }

       return output ;
        
    }
};