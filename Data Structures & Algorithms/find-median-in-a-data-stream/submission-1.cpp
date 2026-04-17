class MedianFinder {
public:


  priority_queue<int>left;
  priority_queue<int , vector<int> , greater<int>>right;


  // here comes the picture which u need to keep in mind the fact 
  // we need to maintain the half portion whicb consists of smaller
  // elements in the left half such that yk we can clearly access the 
  // largest element of that part and we need to maintain a smaller priority 
  // queue such that yk we can clearly access the smallest element
  // of the left section






    MedianFinder() {
        
    }
    
    void addNum(int num) {
        

        if( left.empty() || num < left.top()){
            left.push(num);
        }

        else{
            right.push(num);
        }

        if( right.size() > left.size()){

            int value = right.top();
            right.pop();
            left.push(value);
        }
    }
    
    double findMedian() {
        

        if( left.size() == right.size()){

            return ((left.top() + right.top()))/2.0 ;
        }

        else{
            return left.top();
        }
    }
};
