class Solution {
public:
    int n, m;
    int numIslands(vector<vector<char>>& grid) {
         m = grid.size();
         n = grid[0].size();

        int counter = 0;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '1') {
                    ++counter;
                    bfs(grid, i, j);
                }
            }
        }
        return counter;
    }
    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            int row = front.first;
            int col = front.second;
            if(row > 0 && grid[row -1][col] == '1') {
                grid[row-1][col] = '0';
                q.push({row-1, col});
            }
            if(col > 0 && grid[row][col-1] == '1') {
                grid[row][col-1] = '0';
                q.push({row, col-1});
            }
            if(row +1 < m && grid[row +1][col] == '1') {
                grid[row+1][col] = '0';
                q.push({row+1, col});
            }
            if(col + 1 < n && grid[row][col+1] == '1') {
                grid[row][col+1] = '0';
                q.push({row, col+1});
            }
        }
    }
};
