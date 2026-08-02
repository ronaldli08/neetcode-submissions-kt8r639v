class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> surrounded(n, vector<bool>(m, true));

        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O' && surrounded[i][0]) {
                surrounded[i][0] = false;
                dfs(i,0, n, m, surrounded, board);
            }
            if(board[i][m-1] == 'O' && surrounded[i][m-1]) {
                surrounded[i][m-1] = false;
                dfs(i, m-1, n, m, surrounded, board);
            }
        }
        for(int j = 1; j < m - 1; j++) {
            if(board[0][j] == 'O' && surrounded[0][j]) {
                surrounded[0][j] = false;
                dfs(0,j,n,m,surrounded,board);
            }
            if(board[n-1][j] == 'O' && surrounded[n-1][j]) {
                surrounded[n-1][j] = false;
                dfs(n-1,j,n, m, surrounded,board);
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O' && surrounded[i][j]) board[i][j]= 'X';
            }
        }
    }

    void dfs(int i, int j, int n, int m, vector<vector<bool>>& surrounded, vector<vector<char>>& board) {
        if(i > 0 && board[i-1][j] == 'O' && surrounded[i-1][j]) {
            surrounded[i-1][j] = false;
            dfs(i-1,j,n,m,surrounded,board);
        }
        if(j > 0 && board[i][j-1] == 'O' && surrounded[i][j-1]) {
            surrounded[i][j-1] = false;
            dfs(i,j-1,n,m,surrounded,board);
        }
        if(i < n - 1 && board[i+1][j] == 'O' && surrounded[i+1][j]) {
            surrounded[i+1][j] = false;
            dfs(i+1,j,n,m,surrounded,board);
        }
        if(j < m - 1 && board[i][j+1] == 'O' && surrounded[i][j+1]) {
            surrounded[i][j+1] = false;
            dfs(i,j+1,n,m,surrounded,board);
        }
    }
};
