class Solution {
public:
    vector<vector<string>> output;
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> open(n, vector<bool>(n, true));
        vector<string> cur(n, string(n, '.'));
        dfs(open, 0, n, cur);
        return output;
    }
    void dfs(vector<vector<bool>>& open, int i, int n, vector<string>& cur) {
        if(i == n) {
            output.push_back(cur);
            return;
        }

        for(int j = 0; j < n; j++) {
            if(open[i][j]) {
                vector<vector<bool>> temp = open;
                markClosed(open, i, j, n);
                cur[i][j] = 'Q';
                dfs(open, i+1, n, cur);
                cur[i][j] = '.';
                open = temp;
            }
        }
        
    }
    void markClosed(vector<vector<bool>>& open, int i, int j, int n) {
        for(int a = 0; a < n; a++) {
            open[a][j] = false;
            open[i][a] = false;
            if(i - a >= 0 && j - a >= 0) {
                open[i-a][j-a] = false;
            }
            if(i + a < n && j + a < n) {
                open[i+a][j+a] = false;
            }
            if(i - a >= 0 && j + a < n) {
                open[i-a][j+a] = false;
            }
            if(i + a < n && j - a >= 0) {
                open[i+a][j-a] = false;
            }
        }
    }
};
