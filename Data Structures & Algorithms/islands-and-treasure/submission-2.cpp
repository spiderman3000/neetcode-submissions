class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int dist = 0;
        while (!q.empty()) {
            int qlen = q.size();
            dist++;
            while(qlen--){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                // cout << row << "#" << col << "#" << endl;

                for (int i = 0; i < 4; i++) {
                    int x = row + dirs[i][0];
                    int y = col + dirs[i][1];
                    
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != INT_MAX) {
                        continue;
                    }
                    
                    grid[x][y] = dist;
                    q.push({x, y});
                }
            }
        }
    }
};
