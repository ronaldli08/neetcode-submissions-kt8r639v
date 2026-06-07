class Solution {
public:
    struct Point{
        int row;
        int col;
        int length;
    };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<Point> q;
        q.push({0, 0, 1});
        if(grid[0][0] == 1) return -1;
        while(!q.empty()) {
            Point front = q.front();
            q.pop();
            if(front.row == n - 1 && front.col == n - 1) {
                return front.length;
            }
            int row = front.row;
            int col = front.col;
            if(row > 0) {
                if(grid[row-1][col] == 0){
                    q.push({row-1, col, front.length+1});
                    grid[row-1][col]++;
                }
                if(col > 0 && grid[row-1][col-1]==0){
                    q.push({row-1, col-1, front.length+1});
                    grid[row-1][col-1]++;
                }
                if(col +1<n && grid[row-1][col+1]==0)  {
                    q.push({row-1, col+1, front.length+1});
                    grid[row-1][col+1]++;
                }
            }
            if(row +1 < n) {
                if(grid[row+1][col] == 0) {
                    q.push({row+1, col, front.length+1});
                    grid[row+1][col]++;
                }
                if(col > 0 && grid[row+1][col-1]==0) {
                    q.push({row+1,col-1, front.length+1});
                    grid[row+1][col-1]++;
                }
                if(col+1< n && grid[row+1][col+1]==0) {
                    q.push({row+1, col+1, front.length+1});
                    grid[row+1][col+1]++;
                }
            }
            if(col > 0 && grid[row][col-1] ==0) {
                q.push({row, col-1, front.length+1});
                grid[row][col-1]++;
            }
            if(col +1<n && grid[row][col+1]==0){
                q.push({row, col+1, front.length+1});
                grid[row][col+1]++;
            }
        }
        return -1;
    }
};

