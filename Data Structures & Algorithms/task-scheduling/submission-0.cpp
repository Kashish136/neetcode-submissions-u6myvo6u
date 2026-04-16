class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
         // since in such questions we are moving forward with the approach of the fact that if we start moving from the highest frequency tasks we can do comparatively better as compared to a high frequency tasks

        int freq[26] = {0};

        for( char&ch : tasks){
            freq[ch-'A']++;
        }


        // so at first we ae performing initialization of the task we are storing the frequency of the  tasks which task is appearing how many time 


        priority_queue<int>pq;

        for( int i = 0 ; i < 26 ; i++){

            if(freq[i] > 0){
                pq.push(freq[i]);
            }
        }

        int time = 0;

        while(!pq.empty()){

            int cycle = n+1;
            // we will handle it using a cycle of n+1 elements 

            // because we need to maintain at least n+1 tasks 
            vector<int>store;

            int taskcount = 0;

            while(cycle-- && !pq.empty()){
                if(pq.top() > 1){
                    store.push_back(pq.top()-1);
                }
                pq.pop();
                taskcount++;
            }

            for( int &x : store){
                pq.push(x);
            }


            time += (pq.empty() ? taskcount : n+1);
        }


     return time ;

    }
};
