class Solution {
public:
    string decodeString(string s) {
        



     
        stack<int> countStack;
        stack<string> stringStack;

        string currentString = "";
        int k = 0;

        for(char ch : s){

            if(isdigit(ch)){
                k = k * 10 + (ch - '0');
            }

            else if(ch == '['){
                countStack.push(k);
                stringStack.push(currentString);
                k = 0;
                currentString = "";
            }

            else if(ch == ']'){
                int repeat = countStack.top();
                countStack.pop();

                string prev = stringStack.top();
                stringStack.pop();

                string temp = "";
                for(int i = 0; i < repeat; i++){
                    temp += currentString;
                }

                currentString = prev + temp;
            }

            else{
                currentString += ch;
            }
        }

        return currentString;



















    }
};