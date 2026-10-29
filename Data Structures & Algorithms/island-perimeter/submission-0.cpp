class Solution {
    vector<pair<int,int>> dirs = {{0,-1},{0,1},{-1,0},{1,0}};
public:
    int islandPerimeter(vector<vector<int>>& grid) {
       int r = grid.size();
       int c = grid[0].size();
       int res = 0;

       for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            // curr cell = i,j
            if(!grid[i][j]) continue;

            for(int k=0;k<4;k++){
                int nx = dirs[k].first+i;
                int ny = dirs[k].second+j;
                if(nx < 0 || nx >= r || ny < 0 || ny >= c){
                    res++;
                }
                else {
                    if(grid[nx][ny] == 0) res++;
                }
            }
        }
       }

       return res;
    }
};