class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (dfs(board, word, i, j, 1, n, m, visited)) return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int prog, int& n, int&m, vector<vector<bool>>& visited) {
        if(prog == word.size()) return true;
        if(i > 0 && board[i-1][j] == word[prog] && !visited[i-1][j]) {
            visited[i-1][j] = true;
            if (dfs(board, word, i-1, j, prog+1, n, m, visited)) return true;
            visited[i-1][j] = false;
        }
        if(i < n - 1 && board[i+1][j] == word[prog] && !visited[i+1][j]) {
            visited[i+1][j] = true;
            if (dfs(board, word, i+1, j, prog+1, n, m, visited)) return true;
            visited[i+1][j] = false;
        }
        if(j > 0 && board[i][j-1] == word[prog] && !visited[i][j-1]) {
            visited[i][j-1] = true;
            if (dfs(board, word, i, j-1, prog+1, n, m, visited)) return true;
            visited[i][j-1] = false;
        }
        if(j < m - 1 && board[i][j+1] == word[prog] && !visited[i][j+1]) {
            visited[i][j+1] = true;
            if (dfs(board, word, i, j+1, prog+1, n, m, visited)) return true;
            visited[i][j+1] = false;
        }
        return false;
    }
};
