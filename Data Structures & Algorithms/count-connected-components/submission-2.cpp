#define graph unordered_map<int,vector<int>>
#define node int

class Solution {
    // track one entire graph
    void dfs(graph &g, node startNode, vector<int>& visited){
        if(visited[startNode]) return;
        visited[startNode] = 1;
        vector<int> neighbors = g[startNode];
        for(int neigh : neighbors){
            dfs(g, neigh, visited);
        }
        return;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> visited(n,0);
        graph g;
        for(int i=0;i<edges.size();i++){
            vector<int> edge = edges[i];
            int nodeFrom = edge[0];
            int nodeTo = edge[1];
            g[nodeFrom].push_back(nodeTo);
            g[nodeTo].push_back(nodeFrom);
        }

        int numComponents = 0;
        for(int i=0; i<n;i++){
            if(!visited[i]){
                numComponents++;
                dfs(g,i,visited);
            }
        }
        return numComponents;
    }
};
