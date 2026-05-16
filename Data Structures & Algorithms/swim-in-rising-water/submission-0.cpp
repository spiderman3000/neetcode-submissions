#define node pair<int,int>

class Solution {
    vector<pair<int,int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};

    bool isValidCell(int i, int j, int r, int c){
        return i>=0 && j>=0 && i <= r-1 && j <= c-1;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        priority_queue<pair<int, node>, vector<pair<int,node>>, greater<>>  pq; // <time to reach that node, the node>
        vector<vector<int>> visited(r, vector<int>(c, INT_MAX));

        pq.push({0, {0,0}});
        visited[0][0] = 0; // time taken to reach x, y
        while(!pq.empty()){
            auto [timeCurr, currNode] = pq.top();
            pq.pop();
            for(int i=0;i<4;i++){
                int x = currNode.first + dirs[i].first;
                int y = currNode.second + dirs[i].second;
                if(!isValidCell(x, y, r, c)) continue;
                int minReqTime =  max(grid[currNode.first][currNode.second], grid[x][y]);
                if(visited[x][y] > max(timeCurr,minReqTime)){
                    visited[x][y] = max(timeCurr,minReqTime);
                    pq.push({max(timeCurr,minReqTime), {x, y}});
                }
            }
        }
        return visited[r-1][c-1];
    }
};
