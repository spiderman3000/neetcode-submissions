class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> inDeg(numCourses + 1);

        for (auto pre : prerequisites) {
            auto& c = pre;
            adj[c[1]].push_back(c[0]);
            inDeg[c[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }

        int t = 0;
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            t++;
            auto neigh = adj[curr];
            for (int x : neigh) {
                inDeg[x]--;
                if(inDeg[x] == 0) q.push(x);
            }
        }

        return t == numCourses;
    }
};
