class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

           // Step 1: Build the adjacency list of the graph
        vector<vector<int>> adj(numCourses);
        for (auto &p : prerequisites) {
            int u = p[0], v = p[1];
            adj[u].push_back(v);  // edge u -> v
        }

        // Step 2: Initialize reachable table
        // reachable[u][v] = true means u is a prerequisite for v
        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));

        // Step 3: BFS from each course to find all reachable courses
        for (int i = 0; i < numCourses; i++) {
            vector<bool> visited(numCourses, false);
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int next : adj[node]) {
                    if (!visited[next]) {
                        visited[next] = true;
                        reachable[i][next] = true; // i is a prerequisite for next
                        q.push(next);
                    }
                }
            }
        }

        // Step 4: Answer queries
        vector<bool> ans;
        for (auto &q : queries) {
            int u = q[0], v = q[1];
            ans.push_back(reachable[u][v]);
        }

        return ans;
    }
};
