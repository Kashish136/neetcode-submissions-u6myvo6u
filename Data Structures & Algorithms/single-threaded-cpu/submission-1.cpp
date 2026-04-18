class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        


         int n = tasks.size();

    vector<vector<long long>> events;

    for(int i = 0; i < n; i++){
        events.push_back({tasks[i][0], tasks[i][1], i});
    }

    // 🔥 STEP 1: sort by enqueue time
    sort(events.begin(), events.end());

    // 🔥 STEP 2: min heap {processingTime, index}
    priority_queue<
        pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>
    > pq;

    vector<int> ans;

    long long time = 0;
    int i = 0;

     while(i < n || !pq.empty()){

    // if no available tasks → jump time
    if(pq.empty()){
        time = max(time, events[i][0]);
    }

    // 🔥 push ALL tasks available at current time
    while(i < n && events[i][0] <= time){
        pq.push({events[i][1], events[i][2]});
        i++;
    }

    // pick best task
    auto it = pq.top(); pq.pop();

    long long proc = it.first;
    int idx = it.second;

    time += proc;
    ans.push_back(idx);
}

return ans ;
    }
};