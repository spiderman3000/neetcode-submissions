#define graph unordered_map<int,vector<int>>
#define node int

class Solution {
    bool dfs(graph& g, node curr, vector<int>& visited){
        if(visited[curr]) return false;
        visited[curr] = 1;

        auto& neighbor = g[curr];

        // at most one can be visited.
        int cnt = 0;
        for(int i=0;i<neighbor.size();i++){
            int neigh = neighbor[i];
            if(visited[neigh]) cnt++;
        }

        if(cnt > 1) return false;

         for(int i=0;i<neighbor.size();i++){
            int neigh = neighbor[i];
            if(!visited[neigh] && !dfs(g, neigh, visited)) return false;
        }

        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // What is a valid tree ? 
        // A valid tree can have a single node with multiple child ( out going edge), 
        // but only 1 at max incoming edge 

        // now here the input is undirected 
        // if we choose one node as root, then we have decide the direction, 
        // and it makes just verifying the other edges

        graph g;

        for(const auto& e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        // 0 = root
        // we need to go down the tree, any node that is already visited, cant be seen again, once we start moving,
        // else there is a node with 2 parents, which means no tree

        vector<int> visited(n,0);

        // it can be a forest as well => this is false 
        for(int i=0;i<n;i++){
          if(!visited[i] && !dfs(g, i, visited)) return false;
          break;
        }

        for(int i=0;i<n;i++){
            if(!visited[i]) return false;
        }

        return true;
    }
};
