#define cell pair<int, int>

class Solution {
    vector<cell> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    int row = 0, col = 0;

    bool isValid(cell c,vector<vector<int>>& grid){
        return c.first >= 0 && c.first < row && c.second >=0 && c.second < col;
    }
    bool isWater(cell c, vector<vector<int>>& grid) {
        return grid[c.first][c.second] == -1;
    }
    bool isChest(cell c, vector<vector<int>>& grid) {
        return grid[c.first][c.second] == 0;
    }
    bool isLand(cell c, vector<vector<int>>& grid) {
        return !isWater(c, grid) && !isChest(c, grid);
    }

   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        this->row = grid.size();
        this->col = grid[0].size();

        queue<cell> q;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (isChest({i,j}, grid)) {
                    q.push({i,j});
                }
            }
        }

        while (!q.empty()) {
            cell curr = q.front();
            q.pop();
            for (int i = 0; i < dirs.size(); i++) {
                int nextX = dirs[i].first + curr.first;
                int nextY = dirs[i].second + curr.second;

                if (!isValid({nextX, nextY}, grid)) {
                    continue;
                }

                if (isWater({nextX, nextY}, grid)) {
                    continue;
                }

                if (grid[nextX][nextY] != INT_MAX) {
                    continue;
                }

                grid[nextX][nextY] = grid[curr.first][curr.second] + 1;
                q.push({nextX, nextY});
            }
        }

        return;
    }
};