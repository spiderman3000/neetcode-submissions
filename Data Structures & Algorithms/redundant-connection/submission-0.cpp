class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> inDegrees(n + 1, 0);
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            inDegrees[edges[i][0]]++;
            inDegrees[edges[i][1]]++;
        }
        queue<int> q;
        for(int i=1;i < n+1;i++){
            if(inDegrees[i]==1) q.push(i);
        }
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            inDegrees[node]--;
            auto neighbors = graph[node];
            for(int i=0;i<neighbors.size();i++){
                int next = neighbors[i];
                inDegrees[next]--;
                if(inDegrees[next] == 1) q.push(next);
            }
        }

        for(int i=n-1;i>=0;i--){
            int u = edges[i][0];
            int v = edges[i][1];
            if(inDegrees[u] > 0 && inDegrees[v] > 0){
                return {u,v};
            }
        }

        return {};
    }
};