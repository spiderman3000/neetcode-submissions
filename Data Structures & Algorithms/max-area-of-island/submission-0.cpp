#define island vector<vector<int>>
#define cell pair<int,int> 

class Solution {
    vector<cell> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
    int row = 0, col = 0;

    bool isValid(cell c){
        return c.first >= 0 && c.first < row && c.second >= 0 && c.second < col;
    }

    int bfs(island& grid, cell c, island& visited){
        if(!grid[c.first][c.second] || visited[c.first][c.second]) return 0;
        queue<cell> q;
        q.push(c);
        visited[c.first][c.second] = 1;
        int numComponents = 1;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(int i=0;i<dirs.size();i++){
                int nX = dirs[i].first + curr.first;
                int nY = dirs[i].second + curr.second;
                if(isValid({nX, nY}) && !visited[nX][nY] && grid[nX][nY]){
                    q.push({nX, nY});
                    visited[nX][nY] = 1;            
                    numComponents++;
                }
            }
        }
        return numComponents;
    }
public:
    int maxAreaOfIsland(island& grid) {
        this->row = grid.size();
        this->col = grid[0].size();
        island visited(row, vector<int>(col, 0));   
        int res = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                res = max(res, bfs(grid, {i, j}, visited));
            }
        }
        return res;
    }
};