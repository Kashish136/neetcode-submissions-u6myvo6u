class MinStack {
public:


   stack<int>st;
   stack<int>minstack ;

    MinStack() {
        
    }
    
    void push(int val) {
        

        st.push(val);

        if(minstack.empty() || minstack.top() >= val){
            minstack.push(val);
        }
    }
    
    void pop() {
        
       int val = st.top();
        st.pop();

        if(minstack.top() =  val){
            minstack.pop();
        }
    }
    
    int top() {
        return st.pop();
    }
    
    int getMin() {
        
        return minstack.pop();
    }
};
