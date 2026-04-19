class Solution { // since this is a not directed graph so let ignore calling the instant neighbour here
    bool dfsTraverse(unordered_map<int,vector<int>>& graph, vector<int>& visited, int currNode, int parent){ // true if cycle detected
        if(visited[currNode] == 2){
            return false;
        }
        if(visited[currNode] == 1){
            return true;
        }
        visited[currNode] = 1;
        vector<int> nextNodes = graph[currNode];
        for(int i=0;i<nextNodes.size();i++){
            if(nextNodes[i] == parent) continue;
            if(dfsTraverse(graph,visited,nextNodes[i],currNode)){ 
                return true;
            }
        }
        visited[currNode] = 2;
        return false;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> graph; // adjL
        vector<int> visited(n,0);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][1]].push_back(edges[i][0]);
            graph[edges[i][0]].push_back(edges[i][1]);
        }

        int numberOfConnectedComponents = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                numberOfConnectedComponents++;
                if(dfsTraverse(graph,visited,i,-1)){
                    return false;
                }
            }
            if(numberOfConnectedComponents > 1) return false;
        }
        return true;
    }
};
