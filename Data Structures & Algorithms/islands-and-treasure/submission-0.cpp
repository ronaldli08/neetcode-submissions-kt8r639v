class Solution {
public:

    struct Cell{
        int i;
        int j;
        int dist;
    };

    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<Cell> q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j, 1});
                }
            }
        }
        while(!q.empty()) {
            auto [i, j, dist] = q.front();
            q.pop();
            if(i > 0 && grid[i-1][j] == INT_MAX) {
                grid[i-1][j] = dist;
                q.push({i-1, j, dist + 1});
            }
            if(i < n - 1 && grid[i+1][j] == INT_MAX) {
                grid[i+1][j] = dist;
                q.push({i+1, j, dist + 1});
            }
            if(j > 0 && grid[i][j-1] == INT_MAX) {
                grid[i][j-1] = dist;
                q.push({i, j-1, dist + 1});
            }
            if(j < m-1 && grid[i][j+1] == INT_MAX) {
                grid[i][j+1] = dist;
                q.push({i, j+1, dist + 1});
            }
        }
        
    }
};
