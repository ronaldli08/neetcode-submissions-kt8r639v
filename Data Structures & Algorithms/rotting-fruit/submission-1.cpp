class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minute = 0;

        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();

        int total = 0;

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 2) q.push({i, j});
                else if(grid[i][j] == 1) ++total;
            }
        }

        while(!q.empty()) {
            int size = q.size();
            int oldT = total;
            for(int i =0; i < size;++i) {
                pair<int, int> front = q.front();
                q.pop();
                int row = front.first;
                int col = front.second;
                if(row > 0 && grid[row-1][col] == 1) {
                    grid[row-1][col] = 2;
                    q.push({row-1, col});
                    --total;
                }
                if(row + 1 < m && grid[row+1][col] == 1) {
                    grid[row+1][col] = 2;
                    q.push({row+1, col});
                    --total;
                } 
                if(col > 0 && grid[row][col-1] == 1) {
                    grid[row][col-1] = 2;
                    q.push({row, col-1});
                    --total;
                } 
                if(col + 1 < n && grid[row][col+1] == 1) {
                    grid[row][col+1] = 2;
                    q.push({row, col+1});
                    --total;
                }
            }
            if(oldT != total) ++minute;
        }
        if(total == 0) return minute;
        else return -1;
    }
};
