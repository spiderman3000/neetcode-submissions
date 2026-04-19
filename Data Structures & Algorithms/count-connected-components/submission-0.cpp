class Solution {
    void dfs(unordered_map<int,vector<int>>& graph, unordered_set<int>& visited, int currNode, int parentNode){
        if(visited.count(currNode)){
            return;
        }
        visited.insert(currNode);
        vector<int> nextNodes = graph[currNode];
        for(int i=0;i<nextNodes.size();i++){
            int nextNode = nextNodes[i];
            if(parentNode != nextNode && !visited.count(nextNode)){
                dfs(graph,visited,nextNode,currNode);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> graph; // adjL
        unordered_set<int> visited;
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        int res = 0;
        for(int i=0; i < n;i++){
            if(!visited.count(i)){
                res++;
                dfs(graph,visited,i,-1);
            }
        }

        return res;
    }
};
