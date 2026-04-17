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

        if (left.size() > right.size() + 1) {
           right.push(left.top());
           left.pop();
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



class MedianFinder {
public:
    int freq[101];
    int total;
    MedianFinder() {
        memset(freq, 0, sizeof(freq));
        total = 0;
    }
    void addNum(int num) {
        freq[num]++;
        total++;
    }
    double findMedian() {
        int count = 0;
        if (total % 2 == 1) {
            int mid = total / 2 + 1;
            for (int i = 0; i <= 100; i++) {
                count += freq[i];
                if (count >= mid) return i;
            }
        } else {
            int mid1 = total / 2;
            int mid2 = total / 2 + 1;
            int m1 = -1, m2 = -1;
            for (int i = 0; i <= 100; i++) {
                count += freq[i];
                if (count >= mid1 && m1 == -1) m1 = i;
                if (count >= mid2) {
                    m2 = i;
                    break;
                }
            }
            return (m1 + m2) / 2.0;
        }
        return 0;
    }
}; 
// solution for follow up number 1 , approach no.1 for this concept 

class MedianFinder {
public:
    int freq[101];
    int countFreq;
    priority_queue<int> leftHeap; // < 0
    priority_queue<int, vector<int>, greater<int>> rightHeap; // > 100
    MedianFinder() {
        memset(freq, 0, sizeof(freq));
        countFreq = 0;
    }
    void addNum(int num) {
        if (num >= 0 && num <= 100) {
            freq[num]++;
            countFreq++;
        } 
        else if (num < 0) {
            leftHeap.push(num);
        } 
        else {
            rightHeap.push(num);
        }
    }
    double findMedian() {
        int leftSize = leftHeap.size();
        int rightSize = rightHeap.size();
        int total = leftSize + countFreq + rightSize;
        int mid1 = (total + 1) / 2;
        int mid2 = (total % 2 == 0) ? (total / 2 + 1) : mid1;
        int val1 = getKth(mid1);
        int val2 = getKth(mid2);
        return (val1 + val2) / 2.0;
    }
private:
    int getKth(int k) {
        int leftSize = leftHeap.size();
        // Case 1: in left heap
        if (k <= leftSize) {
            return getFromMaxHeap(leftHeap, k);
        }
        k -= leftSize;
        // Case 2: in freq array
        if (k <= countFreq) {
            int count = 0;
            for (int i = 0; i <= 100; i++) {
                count += freq[i];
                if (count >= k) return i;
            }
        }
        k -= countFreq;
        // Case 3: in right heap
        return getFromMinHeap(rightHeap, k);
    }
    int getFromMaxHeap(priority_queue<int> heap, int k) {
        // copy heap → safe for interview
        while (heap.size() > k) heap.pop();
        return heap.top();
    }
    int getFromMinHeap(priority_queue<int, vector<int>, greater<int>> heap, int k) {
        while (k > 1) {
            heap.pop();
            k--;
        }
        return heap.top();
    }
};




